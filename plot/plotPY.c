#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void plotPY(void *arr, size_t len, char *format, char *color, char *title, char *yLabel, char *xLabel) {
    FILE *fd;
    int *array = (int *) arr;
    char chartDir[50], *chartName = "chart.png";

    system("rm -f ./plot/plotData.py");

    fd = fopen("./plot/plotData.py", "w+");

    if (fd == NULL) {
        printf("File Error\n");
        return;
    }

    // Styles
    int titleFontsize = 27, yFontsize = 20, xFontsize = 20;

    fprintf(fd, "import matplotlib.pyplot as plt\nimport numpy as np\nplot = plt.figure()\n");

    fprintf(fd, "ypoints = np.array([");
    for (int i = 0; i < len; i++) {
        fprintf(fd, "%d, ", array[i]);
    }
    fprintf(fd, "])\n");

    sprintf(chartDir, "/home/%s/%s/%s", getenv("PROJECT_NAME"), getenv("CHART_DIR"), chartName);

    fprintf(
            fd,
            "plt.plot(ypoints, '%s', color='%s')\nplt.title(label='%s', fontsize=%d)\nplt.ylabel('%s', fontsize=%d)\nplt.xlabel('%s', fontsize=%d)\nplt.savefig('%s')\nplt.show()\n",
            format,
            color,
            title,
            titleFontsize,
            yLabel,
            yFontsize,
            xLabel,
            xFontsize,
            chartDir
    );

    fclose(fd);

    system("python3 ./plot/plotData.py");
}