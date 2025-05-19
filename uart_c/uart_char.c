#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "uart_char"
#define BUF_SIZE 1024

static int major;
static char kernel_buffer[BUF_SIZE];
static int open_count = 0;

static int uart_open(struct inode *inode, struct file *file)
{
    open_count++;
    printk(KERN_INFO "uart_char: Device opened %d time(s)\n", open_count);
    return 0;
}

static int uart_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "uart_char: Device closed\n");
    return 0;
}

static ssize_t uart_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
    size_t bytes_to_read = len < BUF_SIZE ? len : BUF_SIZE;

    if (copy_to_user(buf, kernel_buffer, bytes_to_read)) {
        return -EFAULT;
    }

    printk(KERN_INFO "uart_char: Read %zu bytes\n", bytes_to_read);
    return bytes_to_read;
}

static ssize_t uart_write(struct file *file, const char __user *buf, size_t len, loff_t *offset)
{
    size_t bytes_to_write = len < BUF_SIZE ? len : BUF_SIZE;

    if (copy_from_user(kernel_buffer, buf, bytes_to_write)) {
        return -EFAULT;
    }

    printk(KERN_INFO "uart_char: Written %zu bytes\n", bytes_to_write);
    return bytes_to_write;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = uart_open,
    .release = uart_release,
    .read = uart_read,
    .write = uart_write,
};

static struct cdev uart_cdev;
static dev_t dev_num;

static int __init uart_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (ret) {
        printk(KERN_ALERT "uart_char: Failed to allocate major number\n");
        return ret;
    }

    cdev_init(&uart_cdev, &fops);
    ret = cdev_add(&uart_cdev, dev_num, 1);
    if (ret) {
        unregister_chrdev_region(dev_num, 1);
        printk(KERN_ALERT "uart_char: Unable to add cdev\n");
        return ret;
    }

    printk(KERN_INFO "uart_char: Registered with major %d minor %d\n",
           MAJOR(dev_num), MINOR(dev_num));
    return 0;
}

static void __exit uart_exit(void)
{
    cdev_del(&uart_cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "uart_char: Unregistered device\n");
}

module_init(uart_init);
module_exit(uart_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Basic UART char driver skeleton");

