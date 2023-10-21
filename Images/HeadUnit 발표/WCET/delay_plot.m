%subplot(1, 2, 1);

hold on
scatter(sec,data,35,"MarkerEdgeColor",[0.8500 0.3250 0.0980],"MarkerFaceColor",[0.9290 0.6940 0.1250]);
plot(sec, data, 'LineWidth', 1.5);
title('Execution Times');
xlabel('time [s]');
ylabel('distribution of times');
ylim([1 inf]);

%subplot(1, 2, 2);

%scatter(log10(microSec), log10(data), 35, 'MarkerEdgeColor', [0.8500 0.3250 0.0980], 'MarkerFaceColor', [0.9290 0.6940 0.1250]);
%title('Execution Times');
%xlabel('time [μs] (log)');
%ylabel('distribution of times (log)');
