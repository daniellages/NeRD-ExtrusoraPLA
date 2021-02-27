###
# Projeto: NeRD - Extrusora PLA
# Realizado por: Daniel Lages, Miguel Leite, João Tavares
# Data: 20/02/2021
###

import temperatura as tmp
import time

tmp1 = 295.5
target_tmp = 250.0
flag = False
variavel_do_Miguel_aka_delay = 60

while flag == False:
    change_tmp = tmp.DiffTmpExtrude(target_tmp, tmp1)

    if change_tmp != 0:
        tmp1 += change_tmp

    flag = True
    i = 0
    while i < variavel_do_Miguel_aka_delay:
        if not tmp.DelayStabilize(target_tmp, tmp1):
            flag = False
            break

        time.sleep(1)

        i += 1

print(flag)