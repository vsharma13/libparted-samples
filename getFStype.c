#include <error.h>
#include <stdio.h>

#include <parted/parted.h>

int main()
{
    PedFileSystemType* type = NULL;
    while((type = ped_file_system_type_get_next(type)))
    {
        printf("file system name: %s \n",type->name);
    }

    return 0;
}
