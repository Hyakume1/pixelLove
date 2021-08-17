#! /bin/bash

# Terminate already running bar instances
killall -q polybar
# If all your bars have ipc enabled, you can also use 
# polybar-msg cmd quit

# Launch bar1 and bar2
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done
#polybar music --config="/home/e/.config/polybar/configp" &
#polybar songname --config="/home/e/.config/polybar/config" &



polybar example --config="/home/leo/.config/polybar/config" &

echo "Bars launched..."
