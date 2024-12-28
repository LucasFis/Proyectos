class Tank(object):
    def __init__(self,name):
        self.name = name
        self.alive = True
        self.ammo = 6
        self.armor = 2

    def __str__(self):
        if self.alive:
            return f"Tank {self.name}: armor={self.armor}, ammo={self.ammo}"
        else:
            return f"The tank {self.name} got neutralized"
        
    def shoot_to(self, enemy_tank):
        if self.ammo >= 1:
            self.ammo -= 1
            print(self.name, " fires on ", enemy_tank.name)
            enemy_tank.hit()
        else:
            print(self.name, " has no ammo!")
    
    def hit(self):
        self.armor -= 1
        print(f"{self.name} got hitted!")
        if self.armor <= 0:
            self.explode()

    def explode(self):
        self.alive = False
        print(f"{self.name} explodes!")   
            
tanks = {"riqui" : Tank("Riqui"), "blasme" : Tank("Blasme"), "luismi" : Tank("luismi")}
alive_tanks = tanks.__len__()

while alive_tanks > 1:
    
    for elem in tanks.keys():
        print(f"tank name: {tanks[elem]}")      
    
    value1 = input("Who fires? ").lower()
    value2 = input("Who at? ").lower()

    if value1 == value2:
        print("Tanks cant shoot themselves!")
        continue
    
    try:
        first_tank = tanks[value1]
        second_tank = tanks[value2]
    except KeyError as name:
        print("no such tank!",name)
        continue

    if not first_tank.alive or not second_tank.alive:
        print("One of those tanks are dead!")
        continue

    print("*" * 30)

    first_tank.shoot_to(second_tank)

    print("*" * 30)
    
    alive_tanks = 0

    for elem in tanks.keys():
        if tanks[elem].alive:
            alive_tanks += 1


for elem in tanks.keys():
    if tanks[elem].alive:
        print(f"{tanks[elem].name} won!")