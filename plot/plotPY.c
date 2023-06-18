#include "../headers/sharedLib.h"

void plotPY(void *arr, size_t len) {
    FILE *fd;
    int *array = (int *) arr;

    system("rm -f ./plot/plotData.py");

    fd = fopen("./plot/plotData.py", "w+");

    if (fd == NULL) {
        printf("File Error\n");
        return;
    }

    fprintf(fd, "import matplotlib.pyplot as plt\nimport numpy as np\n");

    fprintf(fd, "ypoints = np.array([");
    for (int i = 0; i < len; i++) {
        fprintf(fd, "%d, ", array[i]);
    }
    fprintf(fd, "])\n");

    fprintf(fd, "plt.plot(ypoints, color='r')\nplt.show()\n");

    fclose(fd);

    system("python3 ./plot/plotData.py");
}