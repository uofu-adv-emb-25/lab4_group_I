#include "signaling.h"


void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    xSemaphoreTake(request, portMAX_DELAY);

        data->output = data->input + 5;

    xSemaphoreGive(response, portMAX_DELAY);

    xSemaphoreTake(response, portMAX_DELAY);

    xSemaphoreGive(request, portMAX_DELAY);
    
    
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    BaseType_t result = 0;

    xSemaphoreGive(request, portMAX_DELAY);

    xSemaphoreTake(response, portMAX_DELAY);

    result = signalData -> output;

    xSemaphoreGive(response, portMAX_DELAY);

    xSemaphoreTake(request, portMAX_DELAY);

    return result;
}