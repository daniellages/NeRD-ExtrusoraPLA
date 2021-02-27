###
# Projeto: NeRD - Extrusora PLA
# Realizado por: Daniel Lages, Miguel Leite, João Tavares
# Data: 20/02/2021
###

# Temperatura da Extrusora
# Inputs:
#   current_tmp
#   target_tmp
#   delay para estabilizar a tmp (s)
delay = 60

def DiffTmpExtrude(target_tmp, current_tmp):
    return target_tmp-current_tmp

def DelayStabilize(target_tmp, current_tmp):
    if current_tmp == target_tmp:
        return True
    else:
        return False