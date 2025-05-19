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
	{ 0xfe990052, "gpio_free" },
	{ 0x122c3a7e, "_printk" },
	{ 0x13929d91, "gpio_to_desc" },
	{ 0xf01ce0d5, "gpiod_set_raw_value" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x3e5d99eb, "gpiod_direction_output_raw" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "50ED18CD5D233DD92BDD479");
