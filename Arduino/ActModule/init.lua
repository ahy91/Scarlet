-- Define motor pin
A_SPEED_PIN = 1
A_DIR_PIN = 3

-- Define motor constant
FORWARD = 1
BACKWARD = 0

A_DIR = FORWARD
B_DIR = BACKWARD

FAST = 1020
NORMAL = 500
SLOW = 300
OFF = 0

A_SPEED = NORMAL
B_SPEED = NORMAL

-- Define wifi inform.
SSID = "Burf's Wibro"
PASSWORD = "asdf1234"

-- PORT number
--PORT = 8080
PORT = 8081
--PORT = 8082
--PORT = 8083

-- Connect wifi
print("Connecting to WiFi access point...")
wifi.setmode(wifi.STATION)
wifi.sta.config(SSID, PASSWORD)
wifi.sta.connect()

function startup()
    if file.open("init") == nil then
        print("init.lua deleted or renamed")
    else
        print("Running")
        file.close("init")
        -- the actual application is stored in 'application.lua'
        --dofile("webserver")
        initWebServer()
    end
end

-- Request ip to wibro till get ip
tmr.alarm(1, 1000, 1, function()
    if wifi.sta.getip() == nil then
        print("Waiting for IP address...")
    else
        tmr.stop(1)
        print("WiFi connection established, IP address: " .. wifi.sta.getip())
        tmr.alarm(0, 3000, 0, startup)
    end
end)

function initWebServer()
    print("Creating server...")
    srv = net.createServer(net.TCP)

    srv:listen(PORT, function(conn)
        conn:on("receive", function(sck, payload)
            getOrder(payload)
            sck:send("HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n") 
        end)
        conn:on("sent", function(sck) sck:close() end)
    end)

    print("Webserver ready...")
end

function getOrder(payload)
    -- GET /<url> 
    -- Find slash
    print(payload)
    local dir = string.match(payload, "/...")
    local spd = string.match(payload, "&...")
    print("Direction is ")
    print(dir)
    print("Speed is ")
    print(spd)
    
    if dir == "/off" then
        print("off")
        A_DIR = FORWARD
        A_SPEED = OFF
    elseif dir == "/fwd" then
        print("fwd")
        A_DIR = FORWARD
    elseif dir == "/rvs" then
        print("rvs")
        A_DIR = BACKWARD
    end
        
    if spd == "&fst" then
        print("fst")
        A_SPEED = FAST
    elseif spd == "&slw" then
        print("slw")
        A_SPEED = SLOW
    end

    controlMotor(A_DIR_PIN, A_DIR, A_SPEED_PIN, A_SPEED)
end

function controlMotor(dir_pin, dir, spd_pin, speed)
    if dir == FORWARD then
        gpio.write(dir_pin, gpio.HIGH)
    else
        gpio.write(dir_pin, gpio.LOW)
    end

    pwm.stop(spd_pin)
    pwm.setup(spd_pin, 999, speed)
    pwm.start(spd_pin)
end
