;;******************************************************************************
;; Require font-lock, so we get cool syntax hightlights.
;;******************************************************************************
(require 'font-lock)


;;******************************************************************************
;; load up "xmidas" and "octave" modes.
;;******************************************************************************
(load-library "~/.xemacs/xmidas-mode.el")
(load-library "~/.xemacs/octave-mod.el")
(setq auto-mode-alist(cons '("\\.m$" . octave-mode) auto-mode-alist))


;;******************************************************************************
;; Turn on pending delete, so that you can delete highlighted regions.
;;******************************************************************************
(turn-on-pending-delete)

;;******************************************************************************
;; Custom variables.
;;******************************************************************************


;;******************************************************************************
;; Set up some custom data types to highlight when in CC-mode.
;;******************************************************************************
(defvar temp1 
  '(
     ("\\<\\(VOID\\)\\>"  . font-lock-type-face)
     ("\\<\\(CHAR\\)\\>"  . font-lock-type-face)
     ("\\<\\(CHR08\\)\\>" . font-lock-type-face)
     ("\\<\\(CCHAR\\)\\>" . font-lock-type-face)
     ("\\<\\(BOOLN\\)\\>" . font-lock-type-face)
     ("\\<\\(INT\\(08\\|16\\|32\\|64\\)\\)\\>"   . font-lock-type-face)
     ("\\<\\(UNT\\(08\\|16\\|32\\|64\\)\\)\\>"   . font-lock-type-face)
     ("\\<\\(FLT\\(32\\|64\\|96\\)\\)\\>"        . font-lock-type-face)
     ("\\<\\(CINT\\(08\\|16\\|32\\|64\\)\\)\\>"  . font-lock-type-face)
     ("\\<\\(CUNT\\(08\\|16\\|32\\|64\\)\\)\\>"  . font-lock-type-face)
     ("\\<\\(CFLT\\(32\\|64\\|96\\)\\)\\>"       . font-lock-type-face)
     ("\\<\\(VINT\\(08\\|16\\|32\\|64\\)\\)\\>"  . font-lock-type-face)
     ("\\<\\(VUNT\\(08\\|16\\|32\\|64\\)\\)\\>"  . font-lock-type-face)
     ("\\<\\(VFLT\\(32\\|64\\|96\\)\\)\\>"       . font-lock-type-face)
     ("\\<\\(int\\(8\\|16\\|32\\|64\\)_t\\)\\>"  . font-lock-type-face)
     ("\\<\\(uint\\(8\\|16\\|32\\|64\\)_t\\)\\>" . font-lock-type-face)
   )
   "Extra expressions to hightlight in c-mode."
)

(defvar temp2 nil)
(defvar temp3 nil)
(setq temp2  c-font-lock-keywords-3)
(setq temp3 (append temp1 temp2))
(setq c-font-lock-keywords-3 temp3)

(defvar temp2 nil)
(defvar temp3 nil)
(setq temp2  c++-font-lock-keywords-3)
(setq temp3 (append temp1 temp2))
(setq c++-font-lock-keywords-3 temp3)

;;******************************************************************************
;; Customize CC-MODE.
;;******************************************************************************
(defun my-c-mode-common-hook ()
  (c-set-offset 'defun-block-intro '+)
  (c-set-offset 'substatement-open 0)
  (c-set-offset 'c                 0)
  (c-set-offset 'statement         0)

  (turn-on-font-lock)

)
(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)

(add-hook 'octave-mode-hook
	  (lambda ()
	    (abbrev-mode 1)
	    (auto-fill-mode 1)
	    (if (eq window-system 'x)
		(font-lock-mode 1))))

;;******************************************************************************
;; SETQ stuff.(?)
;;******************************************************************************
(setq delete-key-deletes-forward t)
(setq pop-up-frame-plist '(width 200 height 40 top 0 left 0))
(setq default-frame-plist '(top 0 left 0))

;;******************************************************************************
;; To set the name of the frame.  Check out "C-h v mode-line-format".
;;******************************************************************************
(setq frame-title-format '("%b"))

;;******************************************************************************
;; Global set key stuff.
;;******************************************************************************
(global-set-key "\M-a" 'mark-whole-buffer)
(global-set-key "\M-c" 'copy-primary-selection)
(global-set-key "\M-f" 'isearch-forward)
(global-set-key "\M-k" 'delete-frame)
(global-set-key "\M-m" 'compile)
(global-set-key "\M-n" 'make-frame)
(global-set-key "\M-q" 'save-buffers-kill-emacs)
(global-set-key "\M-r" 'isearch-backward)
(global-set-key "\M-s" 'save-buffer)
(global-set-key "\M-v" 'yank-clipboard-selection)
(global-set-key "\M-o" 'dired-other-frame)
(global-set-key [f1]   'kill-primary-selection)
(global-set-key [button4] 'scroll-down-one)
(global-set-key [button5] 'scroll-up-one)
;;(global-set-key [button4] 'next-line)
;;(global-set-key [button5] 'previous-line)
;;******************************************************************************
;; Other notes:
;;   To execute a LISP command use the scratch buffer, type in a LISP command,
;;   and then type "C-x C-e".
;;
;;******************************************************************************

(setq minibuffer-max-depth nil)
