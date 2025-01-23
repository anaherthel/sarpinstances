#include <math.h>
#include <vector>

using namespace std;

//Manhattan distance in Km for sfsarp instances
constexpr double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}
double CalcManKm(vector<double> &Xs, vector<double> &Ys, vector<double> &Xf, vector<double> &Yf, int I, int J) {
    
    double lat1 = Xf[I];
    double lon1 = Yf[I];
    double lat2 = Xs[J];
    double lon2 = Ys[J];

    constexpr double kmPerDegreeLat = 111.0;

    double deltaLat = abs(lat2 - lat1) * kmPerDegreeLat;
    double avgLat = degreesToRadians((lat1 + lat2) / 2.0);

    double kmPerDegreeLon = kmPerDegreeLat * cos(avgLat);

    double deltaLon = abs(lon2 - lon1) * kmPerDegreeLon;

    double dist = deltaLat + deltaLon;
    
    double factor = pow(10.0, 3);

    return round(dist * factor) / factor;

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

