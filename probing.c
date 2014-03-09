#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main(void)
{
    PedDevice* device = NULL;

    ped_device_probe_all();

    while((device = ped_device_get_next(device)))
        puts(device->path);

    return 0;
}
