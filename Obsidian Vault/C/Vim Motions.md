4 modes in Vim ::

- Normal :: Simply moves cursor around
- Insert :: Use to edit text
- Visual :: Highlights as you move cursor
- Command :: Enter commands


Switching between modes ::

Mode : Key to get into <mode>

- Normal : `Esc`
- Insert : i/I
- Visual : v/V
- Command : :





Basic structure of any command :

command -- count -- motion

- Command :: what
- Count :: how many times
- Motion :: n which direction

Motion :
`j` goes down, `k` goes up, `h` goes left, `l` goes right. `w` moves to right by word, `b` moves to left by word. `V` [capital V] highlights entire paragraph in visual mode.

Count :
So `16j` goes down by 16 lines, `4w` goes to 4 words right.

Command :
- `u` is undo
- `Ctrl + r` is redo
- `dd` deletes the current line
- `y` copies
- `p` pastes without newline;
- `a` starts insert mode, cursor right to cursor; `i` starts insert mode, cursor left to cursor


You can paste over highlighted section. Copy and delete use the same buffer, i.e., paste-after-delete will paste the deleted line. This means delete is actually cut.



Basic colon commands :

- :w saves file
- :q simply quits
- :wq saves and quits