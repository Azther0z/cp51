# Lab_BNK48 
import pygame as pg

# TODO 1 : กำหนด width : 1000 , height : 600 และ FPS : 60
width = 1000 
height = 600
FPS = 60

# TODO 2 : กำหนดค่าสีดังนี้ pink : (197,142,195) , white : (255,255,255)
pink = (197,142,195)
white = (255,255,255)

# TODO 3 : กำหนดความเร็วให้กับ member แต่ละคน [ 3 member ]
ball1_speed = [2,2]
ball2_speed = [-3,4]
ball3_speed = [3,-2]
    # [-3,4]
    # [3,-2]

# TODO 4 : initialize pygame variable and create clock
pg.init()
pg.display.set_caption("Lab_BNK48")
clock = pg.time.Clock()
running = True

# TODO 5 : create screen [pygame.display.set_mode] 
# and set caption [pygame.display.set_caption] => "BNK_BALL (Heavy Collision)"
screen = pg.display.set_mode((width,height))

# TODO 6
#Load sound [change your sound filepath according to your computer]
pg.mixer.init()
pg.mixer.music.load("source/sound.mp3")
pg.mixer.music.play(-1, 0.0)

# ใช้คำสั่ง soundeffect.play() เพื่อเล่นเสียง effect ตอนลูกบอลชนกัน
soundeffect = pg.mixer.Sound("source/effect.wav")

# Choose 3 members from BNK48 and create pygame object from  get_rect
# [ load , resize , get_rect ]

# Member 1 [size : (150 , 150) , center : (500 , 250) ]
ball1_img = pg.image.load("source/BNK48/Wee_cc.png").convert_alpha()
ball1_img = pg.transform.scale(ball1_img, (150, 150))
ball1_rect = ball1_img.get_rect(center=(500,250))

ball2_img = pg.image.load("source/BNK48/Cherprang_cc.png").convert_alpha()
ball2_img = pg.transform.scale(ball2_img, (100, 100))
ball2_rect = ball2_img.get_rect(center=(250,120))

ball3_img = pg.image.load("source/BNK48/Eve_cc.png").convert_alpha()
ball3_img = pg.transform.scale(ball3_img, (120, 120))
ball3_rect = ball3_img.get_rect(center=(800,400))

# TODO 7 : create object with attribute in each comment
# Member 2 [size : (100 , 100) , center : (250 , 120)]




# Member 3 [size : (120 , 120) , center : (800 , 400)]


import math

def do_circles_intersect(x1, y1, x2, y2, r1, r2):
    # Calculate the distance between the centers of the circles
    return (x1-x2)**2 + (y1-y2)**2 <= (r1/2+r2/2)**2

while running:
    # TODO 8 : set ให้ตัวเกมส์แสดงผลด้วยความเร็วที่เหมาะสม [clock.tick(...)]
    clock.tick(FPS) 

    for event in pg.event.get():
        if event.type == pg.QUIT:
            running=False
            pg.quit()

    if running:
        # TODO 9 :ใส่สี background สีชมพู (screen.fill(...))
        
        screen.fill(pink)
        # TODO 10 : ให้ member ทั้ง 3 คนเคลื่อนที่ตามทิศทางและความเร็วเป็นไปตาม speed ของแต่ละคน
        ball1_rect = ball1_rect.move(ball1_speed)
        ball2_rect = ball2_rect.move(ball2_speed) 
        ball3_rect = ball3_rect.move(ball3_speed)
        
        # TOiDO 11 : วาด text คำว่า "Heavy Collision" [size : 150 , center :(width/2 , height/3), สีขาว]
        font_name = pg.font.match_font('arial')  # กำหนดชื่อ Font
        font = pg.font.Font(font_name, 150)  # กำหนดขนาด font
        h_c = font.render("Heavy Collision", True, white)
        h_c_rect = h_c.get_rect()
        h_c_rect.midtop = (width/2, height/3)
        screen.blit(h_c,h_c_rect)




        # TODO 12 : วาด text รหัสนิสิต ลงไป ข้างใต้คำว่า "Heavy Collision" [size : 100 ,center :(width/2 , height/1.5), สีขาว]
        # [ขนาดและตำแหน่งสามารถปรับได้ตามความเหมาะสม]
        font = pg.font.Font(font_name, 100)
        student = font.render("6732017921", True, white)
        student_rect = student.get_rect()
        student_rect.midtop = (width/2, height/1.5)
        screen.blit(student,student_rect)



        # TODO 13 : เขียนเงื่อนไขไม่ให้ตกกรอบทุกด้านให้กับ member ทั้ง 3 คน
        if ball1_rect.left < 0 or ball1_rect.right > width:
            ball1_speed[0] = -ball1_speed[0]
        if ball1_rect.top < 0 or ball1_rect.bottom > height:
            ball1_speed[1] = -ball1_speed[1]

        if ball2_rect.left < 0 or ball2_rect.right > width:
            ball2_speed[0] = -ball2_speed[0]
        if ball2_rect.top < 0 or ball2_rect.bottom > height:
            ball2_speed[1] = -ball2_speed[1]
        
        if ball3_rect.left < 0 or ball3_rect.right > width:
            ball3_speed[0] = -ball3_speed[0]
        if ball3_rect.top < 0 or ball3_rect.bottom > height:
            ball3_speed[1] = -ball3_speed[1]




        

        # Special point ทำให้ลูกบอลชนกันแล้วเด้งในทิศตรงกันข้าม
        if do_circles_intersect(ball1_rect.center[0],ball1_rect.center[1],ball2_rect.center[0],ball2_rect.center[1],ball1_rect.width,ball2_rect.width):
            ball1_speed[0] *= -1
            ball1_speed[1] *= -1
            ball2_speed[0] *= -1
            ball2_speed[1] *= -1
            soundeffect.play()
        if do_circles_intersect(ball3_rect.center[0],ball3_rect.center[1],ball2_rect.center[0],ball2_rect.center[1],ball3_rect.width,ball2_rect.width):
            ball2_speed[0] *= -1
            ball2_speed[1] *= -1
            ball3_speed[0] *= -1
            ball3_speed[1] *= -1
            soundeffect.play()
        if do_circles_intersect(ball1_rect.center[0],ball1_rect.center[1],ball3_rect.center[0],ball3_rect.center[1],ball1_rect.width,ball3_rect.width):
            ball1_speed[0] *= -1
            ball1_speed[1] *= -1
            ball3_speed[0] *= -1
            ball3_speed[1] *= -1
            soundeffect.play()








        ################################################

        # TODO 14 : เอาภาพของ member แต่ละคนใส่ลงใน object ของตนเอง
        screen.blit(ball1_img, ball1_rect)
        screen.blit(ball2_img, ball2_rect)
        screen.blit(ball3_img, ball3_rect)        


        ##########################################################

        pg.display.flip()


