#include "../headers/sharedLib.h"
#include "pbPlots.h"
#include "supportLib.h"
#include "../headers/sharedMacros.h"

void plot(char *title, double *xs, size_t xsLen, double *ys, size_t ysLen) {
    _Bool success;
    StringReference *errorMessage;

    StartArenaAllocator();

    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    double xs2[] = {127, 134, 140};
    double ys2[] = {200, 199, 198};

    ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
    series2->xs = xs2;
    series2->xsLength = 3;
    series2->ys = ys2;
    series2->ysLength = 3;
    series2->linearInterpolation = true;
    series2->lineType = L"solid";
    series2->lineTypeLength = wcslen(series2->lineType);
    series2->lineThickness = 2;
    series2->color = CreateRGBColor(0.4, 0.87, 1);

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->width = 1000;
    settings->height = 1000;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = L"Title";
    settings->titleLength = wcslen(settings->title);
    settings->xLabel = L"X Axis";
    settings->xLabelLength = wcslen(settings->xLabel);
    settings->yLabel = L"Y Axis";
    settings->yLabelLength = wcslen(settings->yLabel);
    ScatterPlotSeries *s[] = {series2};
    settings->scatterPlotSeries = s;
    settings->scatterPlotSeriesLength = 1;

    errorMessage = (StringReference *) malloc(sizeof(StringReference));
    success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    if (success) {
        ByteArray *pngdata = ConvertToPNG(imageReference->image);
        WriteToFile(pngdata, "plot.png");
        DeleteImage(imageReference->image);
    } else {
        fprintf(stderr, "Error: ");
        for (int i = 0; i < errorMessage->stringLength; i++) {
            fprintf(stderr, "%c", errorMessage->string[i]);
        }
        fprintf(stderr, "\n");
    }

    FreeAllocations();

    return success ? 0 : 1;
}