/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432E401Y
 *  by the SysConfig tool.
 */

#include <stddef.h>
#include <stdint.h>

#ifndef DeviceFamily_MSP432E401Y
#define DeviceFamily_MSP432E401Y
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"


/*
 *  ============================= Display =============================
 */

#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>

#define CONFIG_Display_COUNT 1

#define Display_UARTBUFFERSIZE 1024
static char displayUARTBuffer[Display_UARTBUFFERSIZE];

DisplayUart_Object displayUartObject;

const DisplayUart_HWAttrs displayUartHWAttrs = {
    .uartIdx      = CONFIG_UART_0,
    .baudRate     = 115200,
    .mutexTimeout = (unsigned int)(-1),
    .strBuf       = displayUARTBuffer,
    .strBufLen    = Display_UARTBUFFERSIZE
};

const Display_Config Display_config[CONFIG_Display_COUNT] = {
    /* CONFIG_Display_0 */
    /* XDS110 UART */
    {
        .fxnTablePtr = &DisplayUartMin_fxnTable,
        .object      = &displayUartObject,
        .hwAttrs     = &displayUartHWAttrs
    },
};

const uint_least8_t Display_count = CONFIG_Display_COUNT;


/*
 *  =============================== DMA ===============================
 */

#include <ti/drivers/dma/UDMAMSP432E4.h>
#include <ti/devices/msp432e4/inc/msp432.h>
#include <ti/devices/msp432e4/driverlib/interrupt.h>
#include <ti/devices/msp432e4/driverlib/udma.h>

/* Ensure DMA control table is aligned as required by the uDMA Hardware */
static tDMAControlTable dmaControlTable[64] __attribute__ ((aligned (1024)));

/* This is the handler for the uDMA error interrupt. */
static void dmaErrorFxn(uintptr_t arg)
{
    int status = uDMAErrorStatusGet();
    uDMAErrorStatusClear();

    /* Suppress unused variable warning */
    (void)status;

    while (1);
}

UDMAMSP432E4_Object udmaMSP432E4Object;

const UDMAMSP432E4_HWAttrs udmaMSP432E4HWAttrs = {
    .controlBaseAddr = (void *)dmaControlTable,
    .dmaErrorFxn     = (UDMAMSP432E4_ErrorFxn)dmaErrorFxn,
    .intNum          = INT_UDMAERR,
    .intPriority     = (~0)
};

const UDMAMSP432E4_Config UDMAMSP432E4_config = {
    .object  = &udmaMSP432E4Object,
    .hwAttrs = &udmaMSP432E4HWAttrs
};


/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSP432E4.h>

#define CONFIG_GPIO_COUNT 2

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[CONFIG_GPIO_COUNT] = {
    /* CONFIG_GPIO_LED_0 : LaunchPad LED D1 */
    GPIOMSP432E4_PN1 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* CONFIG_GPIO_0 : BOOSTXL-SHARP128 SD SPI Slave Select */
    GPIOMSP432E4_PC7 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_HIGH,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *
 *  NOTE: Unused callback entries can be omitted from the callbacks array to
 *  reduce memory usage by enabling callback table optimization
 *  (GPIO.optimizeCallbackTableSize = true)
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    /* CONFIG_GPIO_LED_0 : LaunchPad LED D1 */
    NULL,
    /* CONFIG_GPIO_0 : BOOSTXL-SHARP128 SD SPI Slave Select */
    NULL,
};

const uint_least8_t CONFIG_GPIO_LED_0_CONST = CONFIG_GPIO_LED_0;
const uint_least8_t CONFIG_GPIO_0_CONST = CONFIG_GPIO_0;

/*
 *  ======== GPIOMSP432E4_config ========
 */
const GPIOMSP432E4_Config GPIOMSP432E4_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = CONFIG_GPIO_COUNT,
    .numberOfCallbacks = 2,
    .intPriority = (~0)
};


/*
 *  =============================== Power ===============================
 */

#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerMSP432E4.h>
#include <ti/devices/msp432e4/inc/msp432.h>

extern void PowerMSP432E4_sleepPolicy(void);

const PowerMSP432E4_Config PowerMSP432E4_config = {
    .policyFxn             = PowerMSP432E4_sleepPolicy,
    .enablePolicy          = true
};


/*
 *  =============================== SD ===============================
 */
#include <ti/drivers/SD.h>
#include <ti/drivers/sd/SDSPI.h>
#include <ti/drivers/SDFatFS.h>

#define CONFIG_SD_COUNT 1
#define CONFIG_SD_FATFS_COUNT 1


SDFatFS_Object sdfatfsObjects[CONFIG_SD_FATFS_COUNT];

const SDFatFS_Config SDFatFS_config[CONFIG_SD_FATFS_COUNT] = {
    /* CONFIG_SDFatFS_0 */
    {
        .object = &sdfatfsObjects[CONFIG_SDFatFS_0]
    },
};

const uint_least8_t SDFatFS_count = CONFIG_SD_FATFS_COUNT;

SDSPI_Object sdspiObjects[CONFIG_SD_COUNT];

static const SDSPI_HWAttrs sdspiHWAttrs[CONFIG_SD_COUNT] = {
    /* CONFIG_SDFatFS_0 */
    /* BOOSTXL-SHARP128 SD Card */
    {
        .spiIndex = CONFIG_SPI_0,
        .spiCsGpioIndex = CONFIG_GPIO_0
    },
};

const SD_Config SD_config[CONFIG_SD_COUNT] = {
    /* CONFIG_SDFatFS_0 */
    /* BOOSTXL-SHARP128 SD Card */
    {
        .fxnTablePtr = &SDSPI_fxnTable,
        .object = &sdspiObjects[CONFIG_SDFatFS_0],
        .hwAttrs = &sdspiHWAttrs[CONFIG_SDFatFS_0]
    },
};

const uint_least8_t CONFIG_SDFatFS_0_CONST = CONFIG_SDFatFS_0;
const uint_least8_t SD_count = CONFIG_SD_COUNT;


/*
 *  =============================== SPI ===============================
 */

#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPIMSP432E4DMA.h>

#include <ti/devices/msp432e4/inc/msp432.h>
#include <ti/devices/msp432e4/driverlib/adc.h>
#include <ti/devices/msp432e4/driverlib/interrupt.h>
#include <ti/devices/msp432e4/driverlib/pwm.h>
#include <ti/devices/msp432e4/driverlib/sysctl.h>
#include <ti/devices/msp432e4/driverlib/udma.h>

#define CONFIG_SPI_COUNT 1

/*
 *  ======== spiMSP432E4DMAObjects ========
 */
SPIMSP432E4DMA_Object spiMSP432E4DMAObjects[CONFIG_SPI_COUNT];

/*
 *  ======== spiMSP432E4DMAHWAttrs ========
 */
const SPIMSP432E4DMA_HWAttrs spiMSP432E4DMAHWAttrs[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-SHARP128 SPI Bus */
    {
        .baseAddr = SSI2_BASE,
        .intNum = INT_SSI2,
        .intPriority = (~0),
        .defaultTxBufValue = ~0,
        .rxDmaChannel = UDMA_CH12_SSI2RX,
        .txDmaChannel = UDMA_CH13_SSI2TX,
        .clkPinMask  = SPIMSP432E4_PD3_SSI2CLK,
        .xdat0PinMask = SPIMSP432E4_PD1_SSI2XDAT0,
        .xdat1PinMask = SPIMSP432E4_PD0_SSI2XDAT1,
        .fssPinMask  = SPIMSP432E4_PIN_NO_CONFIG,
        .minDmaTransferSize = 10
    },
};

/*
 *  ======== SPI_config ========
 */
const SPI_Config SPI_config[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-SHARP128 SPI Bus */
    {
        .fxnTablePtr = &SPIMSP432E4DMA_fxnTable,
        .object = &spiMSP432E4DMAObjects[CONFIG_SPI_0],
        .hwAttrs = &spiMSP432E4DMAHWAttrs[CONFIG_SPI_0]
    },
};

const uint_least8_t CONFIG_SPI_0_CONST = CONFIG_SPI_0;
const uint_least8_t SPI_count = CONFIG_SPI_COUNT;


/*
 *  =============================== UART ===============================
 */

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTMSP432E4.h>
#include <ti/devices/msp432e4/driverlib/interrupt.h>

#define CONFIG_UART_COUNT 1

UARTMSP432E4_Object uartMSP432E4Objects[CONFIG_UART_COUNT];

static unsigned char uartMSP432E4RingBuffer0[32];
static const UARTMSP432E4_HWAttrs uartMSP432E4HWAttrs[CONFIG_UART_COUNT] = {
  {
    .baseAddr           = UART0_BASE,
    .intNum             = INT_UART0,
    .intPriority        = (~0),
    .flowControl        = UARTMSP432E4_FLOWCTRL_NONE,
    .ringBufPtr         = uartMSP432E4RingBuffer0,
    .ringBufSize        = sizeof(uartMSP432E4RingBuffer0),
    .rxPin              = UARTMSP432E4_PA0_U0RX,
    .txPin              = UARTMSP432E4_PA1_U0TX,
    .ctsPin             = UARTMSP432E4_PIN_UNASSIGNED,
    .rtsPin             = UARTMSP432E4_PIN_UNASSIGNED,
    .errorFxn           = NULL
  },
};

const UART_Config UART_config[CONFIG_UART_COUNT] = {
    {   /* CONFIG_UART_0 */
        .fxnTablePtr = &UARTMSP432E4_fxnTable,
        .object      = &uartMSP432E4Objects[CONFIG_UART_0],
        .hwAttrs     = &uartMSP432E4HWAttrs[CONFIG_UART_0]
    },
};

const uint_least8_t CONFIG_UART_0_CONST = CONFIG_UART_0;
const uint_least8_t UART_count = 1;


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    /* Grant the DMA access to all FLASH memory */
    FLASH_CTRL->PP |= FLASH_PP_DFA;

    /* Region start address - match FLASH start address */
    FLASH_CTRL->DMAST = 0x00000000;

    /*
     * Access to FLASH is granted to the DMA in 2KB regions.  The value
     * assigned to DMASZ is the amount of 2KB regions to which the DMA will
     * have access.  The value can be determined via the following:
     *     2 * (num_regions + 1) KB
     *
     * To grant full access to entire 1MB of FLASH:
     *     2 * (511 + 1) KB = 1024 KB (1 MB)
     */
    FLASH_CTRL->DMASZ = 511;

    Board_initHook();
}
