## Тестовое задание на позицию <<Младший научный сотрудник / AME-L1 / algorithms intern>> ##
### Михаил Лашин, 09.2023 ###

Реализация QAM модулятора и демодулятора на C++.

Команда на компиляцию и выполение записана в скрипте ``compile_and_run.sh``

Скрипт на отрисовку графиков ``plot_script.m`` скомпилирован MATLAB 2022b.
Ниже оставлен автоматически генерируемый readme для запуска скомпилированной MATLAB программы.

Итоговый сводный график: ``ebn0_plot_result.jpg``. Можно посмотреть его интерактивную версию как MATLAB-figure ``ebn0_plot_result.fig``

==================================================================================

plot_script Executable

1. Prerequisites for Deployment 

Verify that MATLAB Runtime(R2022b) is installed.
If not, you can run the MATLAB Runtime installer.
To find its location, enter
  
    >>mcrinstaller
      
at the MATLAB prompt.
NOTE: You will need administrator rights to run the MATLAB Runtime installer. 

Alternatively, download and install the Windows version of the MATLAB Runtime for R2022b 
from the following link on the MathWorks website:

    https://www.mathworks.com/products/compiler/mcr/index.html
   
For more information about the MATLAB Runtime and the MATLAB Runtime installer, see 
"Distribute Applications" in the MATLAB Compiler documentation  
in the MathWorks Documentation Center.

2. Files to Deploy and Package

Files to Package for Standalone 
================================
-plot_script.exe
-MCRInstaller.exe 
    Note: if end users are unable to download the MATLAB Runtime using the
    instructions in the previous section, include it when building your 
    component by clicking the "Runtime included in package" link in the
    Deployment Tool.
-This readme file 



3. Definitions

For information on deployment terminology, go to
https://www.mathworks.com/help and select MATLAB Compiler >
Getting Started > About Application Deployment >
Deployment Product Terms in the MathWorks Documentation
Center.




