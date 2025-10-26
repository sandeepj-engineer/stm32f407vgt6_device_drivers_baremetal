/*
 * Std_Types.h
 *
 *  Created on: Oct 26, 2025
 *      Author: Sandeep J
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/**
 * @defgroup Generic_Macros Generic Macros
 * @{
 * @brief Generic macros for enabling/disabling, setting/resetting, and handling flags.
 */
#define ENABLE          1           /**< Enable macro */
#define DISABLE         0           /**< Disable macro */
#define SET             ENABLE      /**< Set macro */
#define RESET           DISABLE     /**< Reset macro */
#define GPIO_PIN_SET    SET         /**< GPIO Pin set macro */
#define GPIO_PIN_RESET  RESET       /**< GPIO Pin reset macro */
#define FLAG_SET        SET         /**< Flag set macro */
#define FLAG_RESET      RESET       /**< Flag reset macro */
/** @} Generic_Macros */

/**
 * @defgroup STM32F407XX_DEFINITIONS Definitions and Macros
 * @{
 * @brief Various definitions and macros for the STM32F407xx MCU.
 */

/** @brief volatile_32bit_register Define for accessing a volatile 32-bit register */
#define __vo    volatile

/** @brief Define for the weak attribute */
#define __weak  __attribute__((weak))

/** @} STM32F407XX_DEFINITIONS */

#endif /* STD_TYPES_H_ */
