/*

Я сподіваюсь шо це тимчасове рішення.

Я не розібрався, як і коли краще в драйвері модему подавати живлення.
Тому зараз це робиться в INIT, з пріорітетом, вищим за пріорітет роботи драйверу модему.

Повинен бути віще ніж MODEM_CELLULAR_INIT_PRIORITY.


*/
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>

LOG_MODULE_REGISTER(board_control, CONFIG_LOG_DEFAULT_LEVEL);

#if defined(CONFIG_MODEM_CELLULAR)

// Напевно треба ще додати перевірку шо визначено alias/lte_power
// #if DT_HAS_COMPAT_STATUS_OKAY(imx93evk_exp_sel) && IS_ENABLED(CONFIG_BOARD_MIMX93_EVK_EXP_SEL_INIT)

struct gpio_dt_spec lte_power = GPIO_DT_SPEC_GET_OR(DT_ALIAS(lte_power), gpios, {0});
// const struct device *modem = DEVICE_DT_GET(DT_ALIAS(modem));

static int board_init_lte_power(void)
{
	int ret = 0;

	if (!gpio_is_ready_dt(&lte_power)) {
        LOG_ERR("Device LTE_POWER is not ready.");
		return 0;
	}

    ret = gpio_pin_configure_dt(&lte_power, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
        LOG_ERR("Unable to configure LTE_POWER.");
		return 0;
	}

	k_msleep(2);    // На всяк випадок є затримка.

	return 0;
}

SYS_INIT(board_init_lte_power, POST_KERNEL, CONFIG_MODEM_CELLULAR_PREINIT_PRIORITY);
#endif /* CONFIG_MODEM_CELLULAR */
