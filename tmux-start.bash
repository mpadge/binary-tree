#!/bin/sh

SESSION="bst"

tmux -2 new-session -d -s $SESSION

tmux new-window -t $SESSION:1 -k -n binary-tree
tmux send-keys -t $SESSION:1 'vim bst.h' C-m
tmux send-keys -t $SESSION:1 ':' 'tabe bst.cpp' C-m
tmux send-keys -t $SESSION:1 '1gt'
tmux split-window -h -p 50
#tmux send-keys -t $SESSION:1 'make' C-m
tmux select-pane -t 0

tmux new-window -t $SESSION:2 -n bst-make
tmux select-window -t $SESSION:2
tmux send-keys -t $SESSION:2 'vim tmux-start.bash' C-m
tmux send-keys -t $SESSION:2 ':' 'tabe makefile' C-m
tmux split-window -h
tmux send-keys -t $SESSION:2 'git status' C-m
tmux select-pane -t 0

tmux select-window -t $SESSION:1

tmux attach -t $SESSION
