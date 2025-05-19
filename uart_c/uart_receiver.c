#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
    int uart_fd = open("/dev/serial0", O_RDONLY | O_NOCTTY);
    if (uart_fd < 0) {
        perror("Failed to open UART");
        return 1;
    }

    struct termios options;
    tcgetattr(uart_fd, &options);
    cfsetispeed(&options, B115200);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CRTSCTS;
    tcsetattr(uart_fd, TCSANOW, &options);

    char buf[256];
    while (1) {
        int len = read(uart_fd, buf, sizeof(buf) - 1);
        if (len > 0) {
            buf[len] = '\0';
            printf("Received: %s", buf);
        }
    }

    close(uart_fd);
    return 0;
}

