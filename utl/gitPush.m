% GIT PUSH
userPro = getenv("USERPROFILE");
git2025 = strcat(userPro,'\GIT25');
cd(git2025);

res = dir("*2025*");

for ii = 1:length(res)
    pathName = sprintf("%s\\%s", res(ii).folder, res(ii).name);
    disp(" ")
    disp("*************************************")
    disp("PUSHING")
    disp(pathName);
    disp("*************************************")
    cd(pathName);
    dos('git add .');
    dos('git commit -m "Updates"');
    dos('git push --verbose');
end

cd(git2025);
