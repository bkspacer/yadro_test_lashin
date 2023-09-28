#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

namespace qam
{

    class AWGN
    {
        public:
            void execute(std::vector<std::complex<double>> &signal, double snr);
            double getMeanPower(std::vector<std::complex<double>> &signal);
    };

    enum Constellation
    {
        BPSK  = 2,
        QPSK  = 4,
        QAM16 = 16,
        QAM64 = 64
    };

    class QAM
    {
        public:
            std::vector<std::complex<double>> initConstellation();

        protected:
            QAM(Constellation constellation) : constellation_(constellation) {}
            virtual ~QAM() = default;
            void normConstellation(std::vector<std::complex<double>> &points);

            Constellation constellation_;

    };

    class ModQAM : public QAM
    {
        public:
            ModQAM() = delete;
            ModQAM(Constellation constellation) : QAM(constellation) {}
            std::vector<std::complex<double>> execute(std::vector<int> &inputBits);
    };

    class DemodQAM : public QAM
    {
        public:
            DemodQAM() = delete;
            DemodQAM(Constellation constellation) : QAM(constellation) {}
            std::vector<int> execute(std::vector<std::complex<double>> &IQpoints);
    };

} // namespace qam