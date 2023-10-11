#include "include/QAM.h"
#include <iostream>
#include <fstream>

#define SNR_LOW -20.0
#define SNR_HIGH 40.0
#define SNR_STEP 2.0

const qam::Constellation MOD = qam::Constellation::QAM64;
const unsigned int dataSize = 10000; 

int main()
{   
    // assign the file with simulation data output results
    std::ofstream out_log;
    out_log.open("ber_snr.txt");

    // print constellation type
    out_log << MOD << std::endl;

    // start simulation for different signal-to-noise values
    for(double SNR = SNR_LOW; SNR < SNR_HIGH; SNR += SNR_STEP)
    {

        /////////////////////////////////////////////////
        // data preparing
        
        std::default_random_engine generator;
        std::uniform_int_distribution<int> data_distribution(0, 1);
        std::vector<int> test_data(dataSize);

        for (int i = 0; i < dataSize; i++)
        {
            test_data[i] = data_distribution(generator);
        }
        
        /////////////////////////////////////////////////
        // modulation
        qam::ModQAM mod_test(MOD);
        auto mod_out = mod_test.execute(test_data);

        /////////////////////////////////////////////////
        // noise adding
        qam::AWGN awgn_test;
        awgn_test.execute(mod_out, SNR);

        /////////////////////////////////////////////////
        // demodulation
        qam::DemodQAM demod_test(MOD);
        auto demod_out = demod_test.execute(mod_out);

        ///////////////////////////////////////////////////
        // error check
        int errNum = 0;
        for (int ind = 0; ind < demod_out.size()-6; ind++)
        {
            (test_data[ind] == demod_out[ind]) ?: errNum++;
        }
        
        // calculate bit error rate 
        double BER = static_cast<double>(errNum) / demod_out.size();

        // calculate EbN0 for current simulation
        double EbN0 = SNR - 10 * std::log10(std::log2(static_cast<double>(MOD))); 

        // write simulation round results to log
        out_log << SNR << " " << EbN0 << " " << BER << std::endl;

    } // for

    return 0;
}