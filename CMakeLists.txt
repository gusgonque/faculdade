cmake_minimum_required(VERSION 3.22)
project(faculdade)

set(CMAKE_CXX_STANDARD 14)

include_directories(AED)

add_executable(faculdade
        AED/Listas/Lista1/1.c
        AED/Listas/Lista1/2.c
        AED/Listas/Lista1/3.c
        AED/Listas/Lista1/4.c
        AED/Listas/Lista1/5.c
        AED/Listas/Lista1/6.c
        AED/Listas/Lista1/7.c
        AED/Listas/Lista1/8.c
        AED/Listas/Lista5AED_Hashing/1/main.c
        AED/Prova1/prova1.c
        AED/Prova2/P2GustavoGoncalvesQueiroz.c
        AED/2020/T2/T2Programa.c
        AED/2020/Trabalho1/Trab1AED.c
        AED/ArvoreAVL.h
        IES/2019emergencial/EF/3.c
        IES/2019emergencial/P1/Codigo/WikiFilmesCodigo.c
        IES/2021/Projeto2/CodigoP2IES.c
        LFA/trab1/Codigo.c
        LFA/trab1/teste.c
        NEPS/2.cpp
        NEPS/266.cpp
        NEPS/3.cpp
        Outros/1.c
        Outros/2.c
        Outros/3.c
        Outros/4.c
        Outros/teste.c
        SD/Converter.c
        URI/C/1001.c
        URI/C/1024.c
        URI/C/1047.c
        URI/C/1049.c
        URI/C/1059.c
        URI/C/1060u.c
        URI/C/1075.c
        URI/C/1094.c
        URI/C/1115.c
        URI/C/1131.c
        URI/C/1134.c
        URI/C/1143.c
        URI/C/1150.c
        URI/C/1153.c
        URI/C/1160.c
        URI/C/1164.c
        URI/C/1181.c
        URI/C/1182.c
        URI/C/1183.c
        URI/C/1184.c
        URI/C/1185.c
        URI/C/1186.c
        URI/C/1187.c
        URI/C/1188.c
        URI/C/1189.c
        URI/C/1190.c
        URI/C/1192.c
        URI/C/1234.c
        URI/C/1235.c
        URI/C/1238.c
        URI/C/1253.c
        URI/C/1255.c
        URI/C/1262.c
        URI/C/1272.c
        URI/C/1435.c
        URI/C/1478.c
        URI/C/1534.c
        URI/C/1541.c
        URI/C/1562_Unfinished.c
        URI/C/1589.c
        URI/C/1827.c
        URI/C/2060.c
        URI/C/2062.c
        URI/C/2165.c
        URI/C/2253.c
        URI/C/2313.c
        URI/C/2483.c
        URI/C++/1061.cpp
        URI/C++/1847.cpp
        teste.c
        teste2.c

        )
add_executable(main AED/Trab2/mainTrab2AED.c AED/Trab2/trab2AED.c AED/Trab2/trab2AED.h AED/Trab2/arvoreBArq.h AED/Trab2/arvoreBArq.c AED/Trab2/listaSimplesArquivo.h AED/Trab2/listaSimplesArquivo.c)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/AED/Trab2/")

add_executable(teste teste.c)
set_target_properties(teste PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
add_executable(mainTrab3AED AED/Trab3/mainTrab3AED.c AED/Trab3/trab3AED.c AED/Trab3/trab3AED.h AED/Trab3/arvoreTRIE_TST.c AED/Trab3/arvoreTRIE_TST.h)
set_target_properties(mainTrab3AED PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/AED/Trab3/")