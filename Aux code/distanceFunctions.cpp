//Manhattan distance for sfsarp instances
double CalcMan (vector<double> &Xs, vector<double> &Ys, vector<double> &Xf, vector<double> &Yf, int I, int J){
    return abs(Xf[I] - Xs[J]) + abs(Yf[I] - Ys[J]);
}

//Euclidean distance for csarp/ghsarp instances
double calcEucDist (vector<double> &Xs, vector<double> &Ys, vector<double> &Xf, vector<double> &Yf, int I, int J){
    double a = pow(Xf[I] - Xs[J], 2);
    double b = pow(Yf[I] - Ys[J], 2);
    return floor(sqrt(a + b)*10)/10;
}

//For ghsarp instances, distances are calculated using the Euclidean distance, and then divided by a scaling factor of 50:

double calcGhsarpDist (vector<double> &Xs, vector<double> &Ys, vector<double> &Xf, vector<double> &Yf, int I, int J){
    return calcEucDist(Xs, Ys, Xf, Yf, I, J)/50;
}

