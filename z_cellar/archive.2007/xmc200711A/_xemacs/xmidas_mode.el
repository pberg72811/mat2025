;;; xmidas-mode.el --- XMidas (& NextMidas) code editing commands for Emacs
;;; Compatible with both v19.34 ... v20.7

;; Maintainer: RDA
;; Keywords: unix, languages

;; This file is modified from awk-mode.el, which is part of GNU Emacs.

;; GNU Emacs is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.

;; GNU Emacs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GNU Emacs; see the file COPYING.  If not, write to the
;; Free Software Foundation, Inc., 59 Temple Place - Suite 330,
;; Boston, MA 02111-1307, USA.

;;; Commentary:

;; Sets up C-mode with support for xmidas-style !-comments and a lightly
;; hacked syntax table.

;;; Code:

(defvar xmidas-mode-syntax-table nil
  "Syntax table in use in XMidas-mode buffers.")

(if xmidas-mode-syntax-table
    ()
  (setq xmidas-mode-syntax-table (make-syntax-table))
  (modify-syntax-entry ?\\ "\\" xmidas-mode-syntax-table)
  (modify-syntax-entry ?\n ">" xmidas-mode-syntax-table)
  (modify-syntax-entry ?\f ">" xmidas-mode-syntax-table)
  (modify-syntax-entry ?\! "<" xmidas-mode-syntax-table)
  (modify-syntax-entry ?\" "\"" xmidas-mode-syntax-table)
  (modify-syntax-entry ?/ "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?* "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?+ "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?- "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?= "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?% "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?< "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?> "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?& "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?| "." xmidas-mode-syntax-table)
  (modify-syntax-entry ?_ "_" xmidas-mode-syntax-table)
  (modify-syntax-entry ?\' "\"" xmidas-mode-syntax-table))

(defvar xmidas-mode-abbrev-table nil
  "Abbrev table in use in XMidas-mode buffers.")
(define-abbrev-table 'xmidas-mode-abbrev-table ())

;; Regexps are eval'd in order, so weakest at the end (verbs & switches)
(defconst xmidas-font-lock-keywords
  (eval-when-compile
    (list
     ;;
     ;; Function names.
     '("^[ \t]*\\(subroutine\\)\\>[ \t]*\\(\\sw+\\)?" 
       (1 font-lock-keyword-face) (2 font-lock-function-name-face nil t))
     ;;
     ;; Blocks.
     (list (concat "^[ \t]*\\("
		   "startmacro\\|endmacro\\|"
		   "startcontrols\\|endcontrols\\|"
		   "procedure\\|endprocedure\\|"
		   "xpipe\\|xcntrl\\|return"
		   "\\)\\>")
	   1 'font-lock-keyword-face)
     ;;
     ;; Labels.
     '("^[ \t]*\\(label\\)[ \t]+\\(\\sw+\\)" 
       (1 font-lock-keyword-face) (2 font-lock-function-name-face nil t))
     ;;
     ;; Flow controls.
     (list (concat "\\<\\("
		   "if\\|then\\|elseif\\|else\\|endif\\|"
		   "while\\|endwhile\\|"
		   "do\\|enddo\\|"
		   "loop\\|endloop\\|"
		   "goto"
		   "\\)\\>")
	   1 'font-lock-type-face)
     ;;
     ;; Builtins.
     (list (concat "\\<\\("
		   "n?and\\|n?or\\|n?[fr]exists?\\|"
		   "n?eq\\|n?eqt\\|n?e\\|n?lt\\|n?gt\\|n?le\\|n?ge\\|"
		   "n?subs?\\|n?eqss?\\|n?anybits\\|n?allbits\\|"
		   "\\)\\>")
	   1 'font-lock-keyword-face)
     ;;
     ;; Types.
     '("\\<\\([ANULFD]:\\)"
	   1 'font-lock-variable-name-face)
     ;;
     ;; Operators.  Is this too much?
     (cons (mapconcat 'identity
		      '("&&" "||" "<=" "<" ">=" ">" "==" "!=" "!~" "~")
		      "\\|")
	   'font-lock-type-face)
     ;;
     ;; Verb & switches (uses MATCH-ANCHORED form)
     '("^[ \t]*\\(\\sw+\\)" (1 font-lock-keyword-face)
       ("/[^0-9]\\sw*" nil nil (0 font-lock-function-name-face)))
     ))
 "Default expressions to highlight in XMidas mode.")

;;;###autoload
(defun xmidas-mode ()
  "Major mode for editing XMidas macros.  This is much like C mode
except for the syntax of comments.  It uses the same keymap as C mode
and has the same variables for customizing indentation.  It has its
own abbrev table and its own syntax table.  The \\[compile] command
will translate the macro.  Middle-mousing on translation errors in the
compile window will move to the corresponding line in the source text.

Much of the functionality was adapted from the \\[fortran-mode] package.

Turning on XMidas mode calls the value of the variable `xmidas-mode-hook'
with no args, if that value is non-nil."
  (interactive)
  (kill-all-local-variables)
;  (require 'cc-mode)
;  (c-initialize-cc-mode)
  (use-local-map xmidas-mode-map)
  (setq major-mode 'xmidas-mode)
  (setq mode-name "XMidas")
  (setq local-abbrev-table xmidas-mode-abbrev-table)
  (set-syntax-table xmidas-mode-syntax-table)
  (make-local-variable 'paragraph-start)
  (setq paragraph-start (concat "$\\|" page-delimiter))
  (make-local-variable 'paragraph-separate)
  (setq paragraph-separate paragraph-start)
  (make-local-variable 'paragraph-ignore-fill-prefix)
  (setq paragraph-ignore-fill-prefix t)
  (make-local-variable 'indent-line-function)
  (setq indent-line-function 'c-indent-line)
  (make-local-variable 'require-final-newline)
  (setq require-final-newline t)
  (make-local-variable 'comment-start)
  (setq comment-start "! ")
  (make-local-variable 'comment-end)
  (setq comment-end "")
  (make-local-variable 'comment-column)
  (setq comment-column 42)
  (make-local-variable 'comment-start-skip)
  (setq comment-start-skip "![^ \t\n]*[ \t]*")
  (make-local-variable 'comment-line-start-skip)
  (setq comment-line-start-skip (concat "[ \t]*" comment-start-skip))
  (make-local-variable 'comment-indent-function)
  (setq comment-indent-function 'c-comment-indent)
  (make-local-variable 'parse-sexp-ignore-comments)
  (setq parse-sexp-ignore-comments t)
  (make-local-variable 'font-lock-defaults)
  (setq font-lock-defaults '(xmidas-font-lock-keywords nil t ((?_ . "w"))))
  (make-local-variable 'indent-line-function)
  (setq indent-line-function 'xmidas-indent-line)
  (make-local-variable 'comment-indent-function)
  (setq comment-indent-function 'xmidas-comment-hook)
  (make-local-variable 'fill-paragraph-function)
  (setq fill-paragraph-function 'xmidas-fill-paragraph)
;;;;;;;;;;;;;;;;;;;;;;;; Compile a macro
  (make-local-variable 'compile-command)
  (make-local-variable 'compilation-file-regexp-alist)
  (make-local-variable 'compilation-error-regexp-alist)
  (make-local-variable 'compilation-read-command)
  (setq compilation-read-command nil)  ; Don't prompt build command
  (setq compile-command
	(concat "if ($?XM_PPID == 0) source $XMDISK/xm/unix/xmstart ; "
		"echo Filename: " buffer-file-name " ; "
		"set xm_args=( mtrans "
		(if (string-match "/mcr/[^/]+\.txt"
				  buffer-file-name) " " "%")
		(file-name-nondirectory buffer-file-name)
		" ) ; source $XMAREA/unix/xm"))
  (setq compilation-file-regexp-alist
	'(("Filename: \\([^ \t\n]+\\)" 1 nil)))
  (setq compilation-error-regexp-alist
	'(("[^, \t\n]+, line \\([0-9]+\\):" nil 1)))

  (run-hooks 'xmidas-mode-hook))

;;;;;;;;;;;;;;;;;;;;;;;; Compile a macro
;; Could put this in init area - trying to overcome bug
;; where recompile doesn't work.  The compile-command doesn't
;; get properly set 
;
;(defun xmidas-mtranslate ()
;  "Translate the current macro file using emacs \\[compile] feature.
;Middle-mouse on the error will reposition the source and error buffers."
;  (interactive)
;  (let ((old-compile-command                compile-command)
;	(old-compilation-file-regexp-alist  compilation-file-regexp-alist)
;	(old-compilation-error-regexp-alist compilation-error-regexp-alist))
;;; Compile command - if not in /mcr/, assume it's a home (%) macro
;   (setq compile-command
;	  (concat "if ($?XM_PPID == 0) source $XMDISK/xm/unix/xmstart ; "
;		  "echo Filename: " buffer-file-name " ; "
;		  "set xm_args=( mtrans "
;		  (if (string-match "/mcr/[^/]+\.txt"
;				    buffer-file-name) " " "%")
;		  (file-name-nondirectory buffer-file-name)
;		  " ) ; source $XMAREA/unix/xm"))
;    (setq compilation-file-regexp-alist
;	  '(("Filename: \\([^ \t\n]+\\)" 1 nil)))
;    (setq compilation-error-regexp-alist
;	  '(("[^, \t\n]+, line \\([0-9]+\\):" nil 1)))
;    (compile compile-command)
;    ;; restore old compile-command
;    (setq compile-command                old-compile-command)
;    (setq compilation-file-regexp-alist  old-compilation-file-regexp-alist)
;    (setq compilation-error-regexp-alist old-compilation-error-regexp-alist)))

;;;;;;;;;;;;;;;;;;;;;;;; Indent stuff
(defvar xmidas-comment-indent-char " "
  "*Single-character string inserted for XMidas comment indentation.
Normally a space.")

(defvar comment-line-start nil
  "*Delimiter inserted to start new full-line comment.")

(defvar comment-line-start-skip nil
  "*Regexp to match the start of a full-line comment.")

(defvar xmidas-comment-region "!$$$"
  "*String inserted by \\[xmidas-comment-region] at start of each \
line in region.")

(defvar xmidas-continuation-indent 5
  "*Extra indentation applied to XMidas continuation lines.")

(defvar xmidas-if-indent 2
  "*Extra indentation applied to IF blocks.")

(defvar xmidas-loop-indent 3
  "*Extra indentation applied to LOOP blocks.")

(defvar xmidas-while-indent 3
  "*Extra indentation applied to WHILE blocks.")

(defvar xmidas-do-indent 3
  "*Extra indentation applied to DO blocks.") 

(defvar xmidas-prog-indent 2
  "*Extra indentation applied to section blocks blocks.  This includes
<first line>, STARTMACRO, STARTCONTROLS, SUBROUTINE, PROCEDURE, CALLP,
XPIPE ON, XCNTRL ON")


(defun xmidas-comment-hook ()
  (save-excursion
    (skip-chars-backward " \t")
    (max (+ 1 (current-column))
	 comment-column)))

(defun xmidas-indent-comment ()
  "Align or create comment on current line.
Existing comments of all types are recognized and aligned.
If the line has no comment, a side-by-side comment is inserted and aligned
if the value of  `comment-start'  is not nil.
Otherwise, a separate-line comment is inserted, on this line
or on a new line inserted before this line if this line is not blank."
  (interactive)
  (beginning-of-line)
  ;; Recognize existing comments of either kind.
  (cond ((looking-at comment-line-start-skip)
	 (xmidas-indent-line))
	((xmidas-find-comment-start-skip) ; catches any inline comment and
					; leaves point after comment-start-skip
	 (if comment-start-skip
	     (progn (goto-char (match-beginning 0))
		    (if (not (= (current-column) (xmidas-comment-hook)))
			(progn (delete-horizontal-space)
			       (indent-to (xmidas-comment-hook)))))
	   (end-of-line)))        ; otherwise goto end of line or sth else?
	;; No existing comment.
	;; If side-by-side comments are defined, insert one,
	;; unless line is now blank.
	((and comment-start (not (looking-at "^[ \t]*$")))
	 (end-of-line)
	 (delete-horizontal-space)
	 (indent-to (xmidas-comment-hook))
	 (insert comment-start))
	;; Else insert separate-line comment, making a new line if nec.
	(t
	 (if (looking-at "^[ \t]*$")
	     (delete-horizontal-space)
	   (beginning-of-line)
	   (insert "\n")
	   (forward-char -1))
	 (insert comment-line-start)
	 (insert-char (if (stringp xmidas-comment-indent-char)
			  (aref xmidas-comment-indent-char 0)
			xmidas-comment-indent-char)
		      (- (xmidas-calculate-indent) (current-column))))))

(defun xmidas-comment-region (beg-region end-region arg)
  "Comments every line in the region.
Puts `xmidas-comment-region' at the beginning of every line in the region.
BEG-REGION and END-REGION are args which specify the region boundaries.
With non-nil ARG, uncomments the region."
  (interactive "*r\nP")
  (let ((end-region-mark (make-marker)) (save-point (point-marker)))
    (set-marker end-region-mark end-region)
    (goto-char beg-region)
    (beginning-of-line)
    (if (not arg)			;comment the region
	(progn (insert xmidas-comment-region)
	       (while (and  (= (forward-line 1) 0)
			    (< (point) end-region-mark))
		 (insert xmidas-comment-region)))
      (let ((com (regexp-quote xmidas-comment-region))) ;uncomment the region
	(if (looking-at com)
	    (delete-region (point) (match-end 0)))
	(while (and  (= (forward-line 1) 0)
		     (< (point) end-region-mark))
	  (if (looking-at com)
	      (delete-region (point) (match-end 0))))))
    (goto-char save-point)
    (set-marker end-region-mark nil)
    (set-marker save-point nil)))

(defun xmidas-previous-statement ()
  "Moves point to beginning of the previous XMidas statement.  Skips
over continuation lines and comments.  Returns `first-statement' if
that statement is the first non-comment XMidas statement in the file,
and nil otherwise."
  (interactive)
  (beginning-of-line)
  (let (not-first-statement)
    (while (and (setq not-first-statement (= (forward-line -1) 0))
		(or (looking-at comment-line-start-skip)
		    (looking-at "[ \t]*$")
		    (and (not (bobp))
			 (= ?& (char-after (- (point) 2)))))))
    (if (not not-first-statement)
	'first-statement)))


;; Need to skip line if last char is "*[^&]&$"
(defun xmidas-next-statement ()
  "Moves point to beginning of the next XMidas statement.  Skips over
continuation lines and comments.  Returns `last-statement' if that
statement is the last non-comment XMidas statement in the file, and
nil otherwise."
  (interactive)
  (let (not-last-statement prev-continue)
    (beginning-of-line)
    (while (let ((continue-line (looking-at ".*[^&]&$")))
	     (and (setq not-last-statement
			(and (= (forward-line 1) 0)
			     (not (eobp))))
		  (or continue-line
		      (looking-at "[ \t]*$")
		      (looking-at comment-line-start-skip)
		      ))))
    (if (not not-last-statement)
 	'last-statement)))

;; Simple syntax with simple indent rules.  First look at previous
;; line determine the indent for the current.  It uses the actual
;; indent for the previous line and adds indent if the prefious
;; line started a block.  Continuation lines are tricky, especially
;; with either single line or block IF statements.  Unusual
;; continuation situations may break the indent calc.
(defun xmidas-calculate-indent ()
  "Calculates the XMidas indent column based on previous lines."
  (let (icol first-statement (case-fold-search t)
	     (xmidas-minimum-statement-indent 0))
    ;; Indentation due to previous line
    (save-excursion
      (setq first-statement (xmidas-previous-statement))
      (if first-statement
	  (setq icol xmidas-minimum-statement-indent)
	(progn
	  (if (= (point) (point-min))
	      (setq icol xmidas-minimum-statement-indent)
	    (setq icol (xmidas-current-line-indentation)))
	  (skip-chars-forward " \t")
          ;; IF block must have a THEN without extra text
	  (cond ((looking-at "if[ \t]+")
		 (if (or (looking-at ".*[ \t]+then[ \t]*\\(!.*\\)?$")
			 (let (then-test)	;IF over continue lines
			   (while (and (looking-at ".*[^&]&$")
				       (= (forward-line 1) 0)
				       ;;search forward for then
				       (not (setq then-test
						  (looking-at ".*[ \t]+then[ \t]*\\(!.*\\)?$")))))
			   then-test))
		     (setq icol (+ icol xmidas-if-indent))))
		((looking-at "else\\(if\\)?\\b")
		 (setq icol (+ icol xmidas-if-indent)))
		((looking-at "loop\\b")
		 (setq icol (+ icol xmidas-loop-indent)))
		((looking-at "label\\b")
		 (setq icol (+ icol xmidas-prog-indent)))
		((looking-at "while\\b")
		 (setq icol (+ icol xmidas-while-indent)))
		((looking-at "do\\b")
		 (setq icol (+ icol xmidas-do-indent)))
		((looking-at "\\(pipe\\|xpipe\\|xcntrl\\)\\(/[^ \t]+\\)?[ \t]+on")
		 (setq icol (+ icol xmidas-prog-indent)))
		((looking-at "startmacro\\b")
		 (setq icol (+ icol xmidas-prog-indent)))
		((looking-at "startcontrols\\b")
		 (setq icol (+ icol xmidas-prog-indent)))
		((looking-at "\\(subroutine\\|procedure\\)\\b")
		 (setq icol (+ icol xmidas-prog-indent)))))))
    ;; Indentation adjust based on current line
    (save-excursion
      (beginning-of-line)
      (cond (first-statement)
	    ((looking-at "[ \t]*$"))
	    ((= ?& (char-after (- (point) 2)))  ; continuation line
	     (setq icol (+ icol xmidas-continuation-indent)))
	    (t
	     (skip-chars-forward " \t")
	     (cond ((looking-at "endif\\b")
		    (setq icol (- icol xmidas-if-indent)))
		   ((looking-at "else\\(if\\)?\\b")
		    (setq icol (- icol xmidas-if-indent)))
		   ((looking-at "endloop\\b")
		    (setq icol (- icol xmidas-loop-indent)))
		   ((looking-at "return\\b")
		    (setq icol (- icol xmidas-if-indent)))
		   ((looking-at "endwhile\\b")
		    (setq icol (- icol xmidas-while-indent)))
		   ((looking-at "enddo\\b")
		    (setq icol (- icol xmidas-do-indent)))
		   ((looking-at "return\\b")
		    (setq icol (- icol xmidas-prog-indent)))
		   ((looking-at "\\(pipe\\|xpipe\\|xcntrl\\)[ \t]+off")
		    (setq icol (- icol xmidas-prog-indent)))
		   ((looking-at "end\\(macro\\|controls\\|subroutine\\|mode\\)\\b")
		    (setq icol (- icol xmidas-prog-indent)))))))
    (if (< icol 0)
	(message "Warning: Attempt to indent beyond left margin.\
Probably an unclosed block."))
    (max 0 icol)))

(defun xmidas-current-line-indentation ()
  "Indentation of current line.  This is the column position of the
first non-whitespace character.  For comment lines, returns
indentation of the first non-indentation text within the comment."
  (save-excursion
    (beginning-of-line)
    (when (looking-at comment-line-start-skip)
      (goto-char (match-end 0))
      (skip-chars-forward
       (if (stringp xmidas-comment-indent-char)
	   xmidas-comment-indent-char
	 (char-to-string xmidas-comment-indent-char))))
    ;; Move past whitespace.
    (skip-chars-forward " \t")
    (current-column)))


(defun xmidas-indent-to-column (col)
  "Indent current line with spaces to column COL."
  (save-excursion
    (beginning-of-line)
    (delete-horizontal-space)
    (indent-to col)
    ;; Indent any comment following code on the same line.
    (if (and comment-start-skip
	     (xmidas-find-comment-start-skip))
	(progn (goto-char (match-beginning 0))
	       (if (not (= (current-column) (xmidas-comment-hook)))
		   (progn (delete-horizontal-space)
			  (indent-to (xmidas-comment-hook))))))
    ))

(defun xmidas-find-comment-start-skip ()
  "Move to past `comment-start-skip' found on current line.
Return t if `comment-start-skip' found, nil if not."
  ;; In order to move point only if comment-start-skip is found, this
  ;; one uses a lot of save-excursions.  Note that re-search-forward
  ;; moves point even if comment-start-skip is inside a string-constant.
  ;; Some code expects certain values for match-beginning and end
  (interactive)
  (if (save-excursion
	(re-search-forward comment-start-skip
			   (save-excursion (end-of-line) (point)) t))
      (let ((save-match-beginning (match-beginning 0))
	    (save-match-end (match-end 0)))
	(if (xmidas-is-in-string-p (match-beginning 0))
	    (save-excursion
	      (goto-char save-match-end)
	      (xmidas-find-comment-start-skip)) ; recurse for rest of line
	  (goto-char save-match-beginning)
	  (re-search-forward comment-start-skip
			     (save-excursion (end-of-line) (point)) t)
	  (goto-char (match-end 0))
	  t))
    nil))

(defun xmidas-is-in-string-p (where)
  "Return non-nil iff WHERE (a buffer position) is inside a XMidas string."
  (save-excursion
    (goto-char where)
    (cond
     ((bolp) nil)			; bol is never inside a string
     ((save-excursion			; comment lines too
	(beginning-of-line)
	(looking-at comment-line-start-skip)) nil)
     (t (let (;; ok, serious now. Init some local vars:
	      (parse-state '(0 nil nil nil nil nil 0))
	      (quoted-comment-start (if comment-start
					(regexp-quote comment-start)))
	      (not-done t)
	      parse-limit
	      end-of-line
	      )
	  ;; move to start of current statement
	  (xmidas-next-statement)
	  (xmidas-previous-statement)
	  ;; now parse up to WHERE
	  (while not-done
	    (if (or ;; skip to next line if:
		 ;; - comment line?
		 (looking-at comment-line-start-skip)
		 ;; - at end of line?
		 (eolp)
		 ;; - not in a string and after comment-start?
		 (and (not (nth 3 parse-state))
		      comment-start
		      (equal comment-start
			     (char-to-string (preceding-char)))))
		(if (> (forward-line) 0)
		    (setq not-done nil))
	      ;; else:
	      ;; if we are at beginning of code line, skip any whitespace
	      (if (bolp) (skip-chars-forward " \t"))
	      ;; find out parse-limit from here
	      (setq end-of-line (save-excursion (end-of-line)(point)))
	      (setq parse-limit (min where end-of-line))
	      ;; parse max up to comment-start, if non-nil and in current line
	      (if comment-start
		  (save-excursion
		    (if (re-search-forward quoted-comment-start end-of-line t)
			(setq parse-limit (min (point) parse-limit)))))
	      ;; now parse if still in limits
	      (if (< (point) where)
		  (setq parse-state (parse-partial-sexp
				     (point) parse-limit nil nil parse-state))
		(setq not-done nil))
	      ))
	  ;; result is
	  (nth 3 parse-state))))))

(defun xmidas-indent-line ()
  "Indent current XMidas macro line based on its contents and on
previous lines.  Comments are indented as either in-line or
full-line comments."
  (interactive)
  (let ((cfi (xmidas-calculate-indent)))
    (save-excursion
      (beginning-of-line)
      (and (not (looking-at comment-line-start-skip))
	   (not (= cfi (xmidas-current-line-indentation)))
	  (xmidas-indent-to-column cfi))
      (beginning-of-line)
      (if (and (not (looking-at comment-line-start-skip))
	       (xmidas-find-comment-start-skip))
	  (xmidas-indent-comment))
      )
    ;; Never leave point in left margin.
    (if (< (current-column) cfi)
	(move-to-column cfi))
    ))

(defun xmidas-indent-new-line ()
  "Reindent the current XMidas line, insert a newline and indent the newline.
An abbrev before point is expanded if variable `abbrev-mode' is non-nil."
  (interactive)
  (if abbrev-mode (expand-abbrev))
  (save-excursion
    (xmidas-indent-line))
  (newline)
  (xmidas-indent-line))

(defun xmidas-split-line ()
  "Break line at point and insert continuation marker and alignment."
  (interactive)
  (delete-horizontal-space)
  (insert "&")
  ;RDA-need to fix for comment lines
  (if (save-excursion (beginning-of-line) (looking-at comment-line-start-skip))
      (insert "\n" comment-line-start " ")
    (insert "\n ")) ; Space after \n important
  (xmidas-indent-line))		; when the cont string is C, c or *.

(defun xmidas-join-line (arg)
  "Join current line to the previous one and re-indent.
With a prefix argument, repeat this operation that many times.
If the prefix argument ARG is negative, join the next -ARG lines.
Continuation lines are correctly handled."
  (interactive "*p")
  (save-excursion
    (when (> 0 arg)
      (setq arg (- arg))
      (forward-line arg))
    (while (not (zerop arg))
      (beginning-of-line)
      (delete-indentation)
      (delete-char 1)
      ;; Remove continuation mark and reduce whitespace
      (let ((bol (save-excursion (beginning-of-line) (point))))
	(and (skip-chars-backward " \t&" bol)
	     (or (and (looking-at "[ \t]+")  ; compress whitespace
		      (replace-match " "))
		 (and (looking-at "&[^&]")   ; don't remove &&
		      (delete-char 1)))))
      (setq arg (1- arg)))
    (xmidas-indent-line)))


;;;;;;;;;;;;;;;;;;;;;;;; end of Indent stuff
(defvar xmidas-mode-map ()
  "Keymap used in XMidas mode.")
(if xmidas-mode-map
    ()
  (setq xmidas-mode-map (make-sparse-keymap))
;;  (define-key xmidas-mode-map ";" 'xmidas-abbrev-start)
  (define-key xmidas-mode-map "\C-c;" 'xmidas-comment-region)
  (define-key xmidas-mode-map "\M-;"  'xmidas-indent-comment)
  (define-key xmidas-mode-map "\M-\n" 'xmidas-split-line)
  (define-key xmidas-mode-map "\n"    'xmidas-indent-new-line)
;;  (define-key xmidas-mode-map "\C-c\C-w" 'xmidas-window-create-momentarily)
  (define-key xmidas-mode-map "\C-c\C-p" 'xmidas-previous-statement)
  (define-key xmidas-mode-map "\C-c\C-n" 'xmidas-next-statement)
  (define-key xmidas-mode-map "\C-c\C-d" 'xmidas-join-line) ; like f90
  (define-key xmidas-mode-map "\M-^"     'xmidas-join-line) ; subvert delete-indentation
;;  (define-key xmidas-mode-map "\C-xnd" 'xmidas-narrow-to-subprogram)
  (define-key xmidas-mode-map "\t" 'xmidas-indent-line)

;  ;; Menu
;  (unless (boundp 'xmidas-mode-menu)
;    (easy-menu-define
;     xmidas-mode-menu xmidas-mode-map ""
;     '("Fortran"
;       ["Toggle Auto-fill" xmidas-auto-fill-mode :style toggle
;        :selected (eq auto-fill-function 'xmidas-do-auto-fill)]
;       ["Toggle abbrev-mode" abbrev-mode :style toggle :selected abbrev-mode]
;       "----"
;       ["Comment-out Region" xmidas-comment-region mark-active]
;       ["Uncomment-out region"
;        (xmidas-comment-region (region-beginning) (region-end) 1)
;        mark-active]
;       ["Indent Region" indent-region mark-active]
;       ["Indent Subprogram" xmidas-indent-subprogram t]
;       "----"
;       ["Beginning of Subprogram" beginning-of-xmidas-subprogram t]
;       ["End of Subprogram" end-of-xmidas-subprogram t]
;       ("Mark"
;        ["Subprogram" mark-xmidas-subprogram t]
;        ["IF Block" xmidas-mark-if t]
;        ["DO Block" xmidas-mark-do t])
;       ["Narrow to Subprogram" xmidas-narrow-to-subprogram t]
;       ["Widen" widen t]
;       "----"
;       ["Temporary column ruler" xmidas-column-ruler t]
;       ["72-column window" xmidas-window-create t]
;       ["Full Width Window"
;        (enlarge-window-horizontally (- (frame-width) (window-width)))
;        (< (window-width) (frame-width))]
;       ["Momentary 72-column window" xmidas-window-create-momentarily t]
;       "----"
;       ["Break Line at Point" xmidas-split-line t]
;       ["Join Line" xmidas-join-line t]
;       ["Fill Statement/Comment" fill-paragraph  t]
;       "----"
;       ["Add imenu menu"
;        (progn (imenu-add-menubar-index)
;               ;; Prod menu bar to update -- is this the right way?
;               (menu-bar-mode 1))
;        (not (and (boundp 'imenu--index-alist)
;		  imenu--index-alist))]))))
)

(defun xmidas-fill-paragraph (&optional justify)
  "Fill surrounding comment block as paragraphs.

Intended as the value of `fill-paragraph-function'."
  (interactive "P")
  (save-excursion
    (beginning-of-line)
    (if (looking-at comment-line-start-skip)
	;; We're in a comment block.  Find the start and end of a
	;; paragraph, delimited either by non-comment lines or empty
	;; comments.  (Get positions as markers, since the
	;; `indent-region' below can shift the block's end).
	(let* ((non-empty-comment (concat "\\(" comment-line-start-skip
					  "\\)" "[^ \t\n]"))
	       (start (save-excursion
			;; Find (start of) first line.
			(while (and (zerop (forward-line -1))
				    (looking-at non-empty-comment)))
			(or (looking-at non-empty-comment)
			    (forward-line)) ; overshot
			(point-marker)))
	       (end (save-excursion
		      ;; Find start of first line past region to fill.
		      (while (progn (forward-line)
				    (looking-at non-empty-comment)))
		      (point-marker))))
	  ;; Indent the block, find the string comprising the effective
	  ;; comment start skip and use that as a fill-prefix for
	  ;; filling the region.
	  (indent-region start end nil)
	  (let ((paragraph-ignore-fill-prefix nil)
		(fill-prefix (progn (beginning-of-line)
				    (looking-at comment-line-start-skip)
				    (match-string 0))))
	    (let (fill-paragraph-function)
	      (fill-region start end justify))) ; with normal `fill-paragraph'
	  (set-marker start nil)
	  (set-marker end nil))))
  t)

(provide 'xmidas-mode)

;; Automatically use xmidas-mode for .txt files in /mcr/ or /home/ ,
;; or .mm files anywhere.  To automatically use xmidas mode on text
;; files in your home directory, uncomment the following line:
(setq auto-mode-alist
      (cons '("/\\(mcr\\|home\\)/[^/]+\\.txt$\\|\\.mm$" . xmidas-mode)
	    auto-mode-alist))
;; Uncomment this to automatically edit .txt files in your home directory
;(setq auto-mode-alist
;      (cons (cons (concat (getenv "HOME") "/[^/]+\\.txt$")  'xmidas-mode)
;	    auto-mode-alist))

;; If viper-mode is set, also hook in xmidas-mode
(and (boundp 'viper-mode)
     (eq viper-mode t)
     (add-hook 'xmidas-mode-hook 'viper-mode))

;;; xmidas-mode.el ends here
