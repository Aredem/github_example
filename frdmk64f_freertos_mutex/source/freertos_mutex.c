/*
 * The Clear BSD License
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

SemaphoreHandle_t xMutex;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void write_task_1(void *pvParameters);
static void write_task_2(void *pvParameters);
static void write_task_3(void *pvParameters);
static void write_task_4(void *pvParameters);
static void write_task_5(void *pvParameters);


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    xMutex = xSemaphoreCreateMutex();

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    if (xTaskCreate(write_task_1, "WRITE_TASK_1", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(write_task_2, "WRITE_TASK_2", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    if (xTaskCreate(write_task_3, "WRITE_TASK_3", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
            pdPASS)
        {
            PRINTF("Task creation failed!.\r\n");
            while (1)
                ;
        }
    if (xTaskCreate(write_task_4, "WRITE_TASK_4", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
            pdPASS)
        {
            PRINTF("Task creation failed!.\r\n");
            while (1)
                ;
        }
    if (xTaskCreate(write_task_5, "WRITE_TASK_5", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
            pdPASS)
        {
            PRINTF("Task creation failed!.\r\n");
            while (1)
                ;
        }

    /* Start scheduling. */
    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Write Task 1 function
 */
static void write_task_1(void *pvParameters)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
	for(int i = 100 ; i > 0 ; i --)
    {

        PRINTF("A\n");
        taskYIELD();

    }
	xSemaphoreGive(xMutex);
	vTaskSuspend(NULL);
}


static void write_task_2(void *pvParameters)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
	for(int i = 100 ; i > 0 ; i --)
    {

        PRINTF("B\n");
        taskYIELD();

    }
	xSemaphoreGive(xMutex);
	vTaskSuspend(NULL);
}
static void write_task_3(void *pvParameters)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
	for(int i = 100 ; i > 0 ; i --)
    {

        PRINTF("C\n");
        taskYIELD();

    }
	xSemaphoreGive(xMutex);
	vTaskSuspend(NULL);
}
static void write_task_4(void *pvParameters)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
	for(int i = 100 ; i > 0 ; i --)
    {

        PRINTF("D\n");
        taskYIELD();

    }
	xSemaphoreGive(xMutex);
	vTaskSuspend(NULL);
}
static void write_task_5(void *pvParameters)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
	for(int i = 100 ; i > 0 ; i --)
    {

        PRINTF("E\n");
        taskYIELD();

    }
	xSemaphoreGive(xMutex);
	vTaskSuspend(NULL);
}
