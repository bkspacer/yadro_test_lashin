#include "../include/QAM.h"

// need for native usage of imaginary unit "1i"
using namespace std::complex_literals; 

namespace qam {

    void AWGN::execute(std::vector<std::complex<double>> &signal, double snr)
    {
        double meanPowerSinal = getMeanPower(signal);
        double meanPowerNoise = meanPowerSinal / (std::pow(10, snr/10));

        // generate normal-distributed noise and add it to the signal
        std::default_random_engine generator;
        std::normal_distribution<double> distribution (0.0, std::sqrt(meanPowerNoise/2));
        for (int i = 0; i < signal.size(); i++)
        {
            signal[i] += distribution(generator) + 1i * distribution(generator); 
        }
    }

    double AWGN::getMeanPower(std::vector<std::complex<double>> &signal)
    {
        // calculate norm of each complex sample of signal
        std::vector<double> sigPowers(signal.size());
        for (int i = 0; i < sigPowers.size(); i++)
        {
            sigPowers[i] = (std::norm(signal[i]));
        }
        
        // get mean  
        return std::accumulate(sigPowers.begin(), sigPowers.end(), 0.0) / sigPowers.size();
    }

    //////////////////////////////////////////////

    std::vector<std::complex<double>> QAM::initConstellation()
    {
        std::vector<std::complex<double>> points = {};

        // constellation configurations
        switch (constellation_)
        {
            case Constellation::BPSK:

                points.push_back({ 1.0, 0.0}); // 0 | 0
                points.push_back({-1.0, 0.0}); // 1 | 1

                break;

            case Constellation::QPSK:

                points.push_back({-1.0,  1.0}); //0 | 00
                points.push_back({-1.0, -1.0}); //1 | 01
                points.push_back({ 1.0,  1.0}); //2 | 10
                points.push_back({ 1.0, -1.0}); //3 | 11

                break;


            case Constellation::QAM16:

                points.push_back({-3.0,  3.0}); //0  | 0000
                points.push_back({-3.0,  1.0}); //1  | 0001
                points.push_back({-3.0, -3.0}); //2  | 0010
                points.push_back({-3.0, -1.0}); //3  | 0011

                points.push_back({-1.0,  3.0}); //4  | 0100
                points.push_back({-1.0,  1.0}); //5  | 0101
                points.push_back({-1.0, -3.0}); //6  | 0110
                points.push_back({-1.0, -1.0}); //7  | 0111

                points.push_back({ 3.0,  3.0}); //8  | 1000
                points.push_back({ 3.0,  1.0}); //9  | 1001
                points.push_back({ 3.0, -3.0}); //10 | 1010
                points.push_back({ 3.0, -1.0}); //11 | 1011

                points.push_back({ 1.0,  3.0}); //12 | 1100
                points.push_back({ 1.0,  1.0}); //13 | 1101
                points.push_back({ 1.0, -3.0}); //14 | 1110
                points.push_back({ 1.0, -1.0}); //15 | 1111

                break;

            case Constellation::QAM64:

                points.push_back({-7.0,  7.0}); //0  | 000 000
                points.push_back({-7.0,  5.0}); //1  | 000 001
                points.push_back({-7.0,  1.0}); //2  | 000 010
                points.push_back({-7.0,  3.0}); //3  | 000 011

                points.push_back({-7.0, -7.0}); //4  | 000 100
                points.push_back({-7.0, -5.0}); //5  | 000 101
                points.push_back({-7.0, -1.0}); //6  | 000 110
                points.push_back({-7.0, -3.0}); //7  | 000 111
                ///////////////////////////////
                points.push_back({-5.0,  7.0}); //8  | 001 000
                points.push_back({-5.0,  5.0}); //9  | 001 001
                points.push_back({-5.0,  1.0}); //10 | 001 010
                points.push_back({-5.0,  3.0}); //11 | 001 011

                points.push_back({-5.0, -7.0}); //12 | 001 100
                points.push_back({-5.0, -5.0}); //13 | 001 101
                points.push_back({-5.0, -1.0}); //14 | 001 110
                points.push_back({-5.0, -3.0}); //15 | 001 111
                ///////////////////////////////
                points.push_back({-1.0,  7.0}); //16 | 010 000
                points.push_back({-1.0,  5.0}); //17 | 010 001
                points.push_back({-1.0,  1.0}); //18 | 010 010
                points.push_back({-1.0,  3.0}); //19 | 010 011

                points.push_back({-1.0, -7.0}); //20 | 010 100
                points.push_back({-1.0, -5.0}); //21 | 010 101
                points.push_back({-1.0, -1.0}); //22 | 010 110
                points.push_back({-1.0, -3.0}); //23 | 010 111
                ///////////////////////////////
                points.push_back({-3.0,  7.0}); //24 | 011 000
                points.push_back({-3.0,  5.0}); //25 | 011 001
                points.push_back({-3.0,  1.0}); //26 | 011 010
                points.push_back({-3.0,  3.0}); //27 | 011 011

                points.push_back({-3.0, -7.0}); //28 | 011 100
                points.push_back({-3.0, -5.0}); //29 | 011 101
                points.push_back({-3.0, -1.0}); //30 | 011 110
                points.push_back({-3.0, -3.0}); //31 | 011 111
                ///////////////////////////////
                points.push_back({ 7.0,  7.0}); //32 | 100 000
                points.push_back({ 7.0,  5.0}); //33 | 100 001
                points.push_back({ 7.0,  1.0}); //34 | 100 010
                points.push_back({ 7.0,  3.0}); //35 | 100 011

                points.push_back({ 7.0, -7.0}); //36 | 100 100
                points.push_back({ 7.0, -5.0}); //37 | 100 101
                points.push_back({ 7.0, -1.0}); //38 | 100 110
                points.push_back({ 7.0, -3.0}); //39 | 100 111
                ///////////////////////////////
                points.push_back({ 5.0,  7.0}); //40 | 101 000
                points.push_back({ 5.0,  5.0}); //41 | 101 001
                points.push_back({ 5.0,  1.0}); //42 | 101 010
                points.push_back({ 5.0,  3.0}); //43 | 101 011

                points.push_back({ 5.0, -7.0}); //44 | 101 100
                points.push_back({ 5.0, -5.0}); //45 | 101 101
                points.push_back({ 5.0, -1.0}); //46 | 101 110
                points.push_back({ 5.0, -3.0}); //47 | 101 111
                ///////////////////////////////
                points.push_back({ 1.0,  7.0}); //48 | 110 000
                points.push_back({ 1.0,  5.0}); //49 | 110 001
                points.push_back({ 1.0,  1.0}); //50 | 110 010
                points.push_back({ 1.0,  3.0}); //51 | 110 011

                points.push_back({ 1.0, -7.0}); //52 | 110 100
                points.push_back({ 1.0, -5.0}); //53 | 110 101
                points.push_back({ 1.0, -1.0}); //54 | 110 110
                points.push_back({ 1.0, -3.0}); //55 | 110 111
                ///////////////////////////////
                points.push_back({ 3.0,  7.0}); //56 | 111 000
                points.push_back({ 3.0,  5.0}); //57 | 111 001
                points.push_back({ 3.0,  1.0}); //58 | 111 010
                points.push_back({ 3.0,  3.0}); //59 | 111 011

                points.push_back({ 3.0, -7.0}); //60 | 111 100
                points.push_back({ 3.0, -5.0}); //61 | 111 101
                points.push_back({ 3.0, -1.0}); //62 | 111 110
                points.push_back({ 3.0, -3.0}); //63 | 111 111

                break;

            default:
                //error 'Unknown constellation' ;
                break;
        }

        //normalize signal constellation to power 1
        normConstellation(points);

        return points;
    }

    void QAM::normConstellation(std::vector<std::complex<double>> &points)
    /*Normalize signal constellation to power 1*/
    {
        double sumPower = 0;
        for (int i = 0; i < points.size(); i++)
        {
            sumPower += std::norm(points[i]);
        }

        double normCoef = std::sqrt(points.size() / sumPower);

        for (int i = 0; i < points.size(); i++)
        {
            points[i] *= normCoef;
        }
    }


    //////////////////////////////////////////////

    std::vector<std::complex<double>> ModQAM::execute(std::vector<int> &inputBits)
    {
        // get constellation points
        auto points = initConstellation();

        // get number of bits per one contellation point 
        int numBits = static_cast<int>(log2(constellation_));
   
        // init output IQ-points vector
        std::vector<std::complex<double>> outputIQ(inputBits.size() / numBits);

        // mapping 
        for (int i = 0; i + numBits < inputBits.size(); i += numBits)
        {
            // translate binary digits into decimal numbers
            int decSym = 0;
            for (int j = 0; j < numBits; j++)
            {
                decSym += static_cast<int>(std::pow(2, numBits - j - 1) * inputBits[i + j]);
            }
            outputIQ[i / numBits] = points[decSym];
        }
        
        return outputIQ;
    }

    //////////////////////////////////////////////

    std::vector<int> DemodQAM::execute(std::vector<std::complex<double>> &IQpoints)
    {
        // get constellation points
        auto points = initConstellation();

        // get number of bits per one contellation point 
        int numBits = static_cast<int>(log2(constellation_));

        // init output bit vector
        std::vector<int> outputBits(IQpoints.size() * numBits);

        // HARD DECISION:
        for (int i = 0; i < IQpoints.size(); i++)
        {
            // compute distances to all constellation points 
            std::vector<double> distances(constellation_);
            for (int dot = 0; dot < constellation_; dot++)
            {
                distances[dot] = std::norm(points[dot] - IQpoints[i]);
            }

            // find min among distances to constellation points and get points' number decimal representation
            int decimalPoint = std::distance(distances.begin(),(std::min_element(distances.begin(), distances.end())));

            // convert decimal point number to binaries
            for (int j = numBits - 1; j >= 0; j--)
            {
                outputBits[i * numBits + j] = decimalPoint % 2;
                decimalPoint /= 2;
            }
        }

        return outputBits;
    }

} // namespace qam
