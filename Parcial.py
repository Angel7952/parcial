def calcular_dano(dano_base: int, armadura: int, tipo_bala: int):
    if tipo_bala == 1:
        nombre_bala = "Bala normal"
    elif tipo_bala == 2:
        nombre_bala = "Bala perforante"
    elif tipo_bala == 3:
        nombre_bala = "Bala explosiva"
    else:
        print("Error: Tipo de bala inválido.")
        return
    
    print(f"Tipo de bala seleccionada: {nombre_bala}")
    
    dano_final = dano_base
    if tipo_bala == 1:  
        dano_final -= armadura
    elif tipo_bala == 2: 
        dano_final -= armadura / 2
    elif tipo_bala == 3:  
        dano_final = dano_base * 2 - armadura

    if dano_final < 0:
        dano_final = 0

    es_critico = False
    if dano_base > 50:
        if armadura < 20:
            es_critico = True

    if es_critico:
        dano_final *= 2 
        if dano_final > 100:
            dano_final = 100  

    
    if es_critico:
        print("¡GOLPE CRÍTICO!")
    print(f"Daño recibido: {dano_final:.2f}")

dano_base = int(input("Ingrese el daño base: "))
armadura = int(input("Ingrese la armadura del objetivo: "))
tipo_bala = int(input("Ingrese el tipo de bala (1 = Normal, 2 = Perforante, 3 = Explosiva): "))

calcular_dano(dano_base, armadura, tipo_bala)