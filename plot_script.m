clear all;

fileID = fopen('ber_snr.txt','r');

mod_type = fscanf(fileID, "%d", 1);
switch (mod_type)
    case 2
        constellation = "BPSK";
    case 4
        constellation = "QPSK";
    case 16
        constellation = "QAM16";
    case 64
        constellation = "QAM64";
end

formatSpec = '%f %f %f';
data = fscanf(fileID, formatSpec, [3 Inf]);
SNR  = data(1, :);
EbN0 = data(2, :);
BER  = data(3, :);
fclose(fileID);


figure; 
semilogy(SNR, BER, '-s', 'LineWidth', 2 );
grid on;
title(constellation);
xlim ([min(SNR), max(SNR(BER>0))+1]);
xlabel('SNR, dB');
ylabel('BER');

figure; 
semilogy(EbN0, BER, '-s', 'LineWidth', 2 );
grid on;
title(constellation);
%xlim ([min(EbN0), max(EbN0(BER>0))+1]);
xlabel('EbN0, dB');
ylabel('BER');