#include "signaling.h"


void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    xSemaphoreTake(request, portMAX_DELAY);

        data->output = data->input + 5;

    xSemaphoreGive(response);

    xSemaphoreTake(response, portMAX_DELAY);

    xSemaphoreGive(request);
    
    
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{

    xSemaphoreGive(request);

    if (!xSemaphoreTake(response, portMAX_DELAY))
        return 0;

    xSemaphoreGive(response);

    if (!xSemaphoreTake(request, portMAX_DELAY))
        return 0;

    return 1;
}