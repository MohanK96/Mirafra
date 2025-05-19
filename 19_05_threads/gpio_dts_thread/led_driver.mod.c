#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xed6af888, "__platform_driver_register" },
	{ 0x7135ea23, "kthread_stop" },
	{ 0x13929d91, "gpio_to_desc" },
	{ 0xf01ce0d5, "gpiod_set_raw_value" },
	{ 0xfe990052, "gpio_free" },
	{ 0x122c3a7e, "_printk" },
	{ 0xa223bac6, "platform_driver_unregister" },
	{ 0x810fcbf6, "of_get_named_gpio" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x3e5d99eb, "gpiod_direction_output_raw" },
	{ 0x678b0c30, "kthread_create_on_node" },
	{ 0x5a543dd9, "wake_up_process" },
	{ 0x1a283f39, "_dev_info" },
	{ 0xf810f451, "_dev_err" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Ctechdhaba,led-blink");
MODULE_ALIAS("of:N*T*Ctechdhaba,led-blinkC*");

MODULE_INFO(srcversion, "4774626E26D9425D11F1225");
