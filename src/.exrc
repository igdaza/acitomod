if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
map! <S-Insert> <MiddleMouse>
map  :tabnext
map  :tabprev
nmap gx <Plug>NetrwBrowseX
map <F2> ^0i//j0
map <F12> :cnext
map <F11> :cprevious
map <F9> ma :w
map <F8> :q
map <F6> :%s/\t/  /g
map <F7> :!ctags ./include/*.h ./src/*.c 
map <F5> :w
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
map <S-Insert> <MiddleMouse>
inoremap 	 =Mosh_Tab_Or_Complete()
iabbr _coment /**<   */4hi
iabbr _function /** 
iabbr _struct /** 
iabbr _head /** 
iabbr _comentario //************************************************************************
iabbr _linea //************************************************************************
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set cindent
set cmdheight=3
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=es
set ignorecase
set mouse=v
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim72,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set showmatch
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set termencoding=utf-8
set visualbell
set window=39
" vim: set ft=vim :