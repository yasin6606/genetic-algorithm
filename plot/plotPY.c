#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void plotPY(void *arr, size_t len, char *format, char *color, char *title, char *yLabel, char *xLabel,
            char *answerLabel) {
    FILE *fd;
    int *array = (int *) arr, figDPI;
    char chartDir[SPRINTF_STRING_LEN], *chartName = "chart.png";

    system("rm -f ./plot/plotData.py");

    fd = fopen("./plot/plotData.py", "w+");

    if (fd == NULL) {
        printf("File Error\n");
        return;
    }

    // Styles
    int titleFontsize = 27, yFontsize = 20, xFontsize = 20;

    if (getenv("CHART_DIR"))
        figDPI = 1024;
    else
        figDPI = 100;

    fprintf(
            fd,
            "import matplotlib.pyplot as plt\nimport numpy as np\nplot = plt.figure()\nplot.dpi = %d\n",
            figDPI
    );

    fprintf(fd, "ypoints = np.array([");
    for (int i = 0; i < len; i++) {
        fprintf(fd, "%d, ", array[i]);
    }
    fprintf(fd, "])\n");

    sprintf(chartDir, "/home/%s/%s/%s", getenv("PROJECT_NAME"), getenv("CHART_DIR"), chartName);

    fprintf(
            fd,
            "plt.plot(ypoints, '%s', color='%s', label='%s')\nplt.title(label='%s', fontsize=%d)\nplt.ylabel('%s', fontsize=%d)\nplt.xlabel('%s', fontsize=%d)\nplt.legend()\nplt.show()\nplt.savefig('%s')\n",
            format,
            color,
            answerLabel,
            title,
            titleFontsize,
            yLabel,
            yFontsize,
            xLabel,
            xFontsize,
            chartDir
    );

    fclose(fd);

    printf("\nThe result chart is saved as \"%s\" in %s/Desktop/%s\n\n", chartName, getenv("USER_HOME"), getenv("CHART_DIR"));

    free(array);

    system("python3 ./plot/plotData.py");
}
