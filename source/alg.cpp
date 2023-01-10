int min(int a, int b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

double min(double a, double b) {
    return (a > b) ? b : a;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int allowableRange(int val, int minVal, int maxVal) {
    return min(max(minVal, val), maxVal);
}

