% AA236B HW1 vibration experiment analysis

% import data
test1 = importdata("vibeTest1.txt"," ");
test2 = importdata("vibeTest2.txt"," ");
test3 = importdata("vibeTest3.txt"," ");
test4 = importdata("vibeTest4.txt"," ");
test5 = importdata("vibeTest5.txt"," ");

% plot results
figure()
plot(test1(:,1)/1000,test1(:,2))
hold on
plot(test2(:,1)/1000,test2(:,2))
plot(test3(:,1)/1000,test3(:,2))
plot(test4(:,1)/1000,test4(:,2))
plot(test5(:,1)/1000,test5(:,2))
xlabel('Time (sec)')
ylabel('Vibration amplitude')
legend("Test 1","Test 2","Test 3","Test 4","Test 5")