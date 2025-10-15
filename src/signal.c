#include "signaling.h"


void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    // Take request
    xSemaphoreTake(request, 1000);

    data->output = data->input + 5;

    // Make response
    xSemaphoreGive(response);  
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    // Make request
    xSemaphoreGive(request);

    // Take response
    return xSemaphoreTake(response, 1000);
}