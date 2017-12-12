#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/moduleparam.h>	/* module_param() and MODULE_PARM_DESC() */

#include <linux/fs.h>		/* struct file_operations, struct file */
#include <linux/miscdevice.h>	/* struct miscdevice and misc_[de]register() */
#include <linux/mutex.h>	/* mutexes */
#include <linux/string.h>	/* memchr() function */
#include <linux/slab.h>		/* kzalloc() function */
#include <linux/sched.h>	/* wait queues */
#include <linux/uaccess.h>	/* copy_{to,from}_user() */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("V");
MODULE_DESCRIPTION("TEST module");

static unsigned int test_mode = 0;
module_param(test_mode, uint, (S_IRUSR | S_IRGRP | S_IROTH));
MODULE_PARM_DESC(test_mode, " [mode0|mode0] default mode0");

static unsigned int test_step = 1;
module_param(test_step, uint, (S_IRUSR | S_IRGRP | S_IROTH));
MODULE_PARM_DESC(test_step, "step");


static int __init test_init(void)
{
	
	if (!test_mode)
	    return -1;
	
	if (!test_step)
	    return -1;

	printk(KERN_INFO "TEST module loaded !\n");
	return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit test_cleanup(void)
{
	printk(KERN_INFO "Cleaning up TEST.\n");
}

module_init(test_init);
module_exit(test_cleanup);
