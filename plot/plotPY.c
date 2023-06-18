#include "../headers/sharedLib.h"

void plotPY(void *arr, size_t len) {
    FILE *fd;
    int *array = (int *) arr;

    // Remove existed data file
    system("rm -f ./plot/plotData.py");

    // Open a file
    fd = fopen("./plot/plotData.py", "w+");

    // Checking errors
    if (fd == NULL) {
        printf("File Error\n");
        return;
    }

    // Start writing on the file
    fprintf(fd, "import matplotlib.pyplot as plt\nimport numpy as np\n");

    // Add array
    fprintf(fd, "ypoints = np.array([");
    for (int i = 0; i < len; i++) {
        fprintf(fd, "%d, ", array[i]);
    }
    fprintf(fd, "])\n");

    fprintf(fd, "plt.plot(ypoints, color='r')\nplt.show()\n");

    fclose(fd);

    // Run Python file so as to plot the chart
    system("python3 ./plot/plotData.py");
}