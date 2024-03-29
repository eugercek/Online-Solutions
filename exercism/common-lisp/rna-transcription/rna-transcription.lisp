(in-package #:cl-user)
(defpackage #:rna-transcription
  (:use #:cl)
  (:export #:to-rna))
(in-package #:rna-transcription)

;; Simpler solution
;; (defvar nucleotid-map                   ; For green guys
;;     '((#\G . #\C)
;;       (#\C . #\G)
;;       (#\T . #\A)
;;       (#\A . #\U)))

;; (defun nuc-comp (char)
;;   (cdr (assoc char nucleotid-map)))

;; (defun to-rna (str)
;;   "Transcribe a string representing DNA nucleotides to RNA."
;;   (map 'string #'nuc-comp (string str))) ; Extra (string) is for char inputs

;; (defmacro comp (nuc &body body)
;;   (let ((pairs
;;           (loop for (a b) in body
;;                 collect `(,a ,b))))
;;     `(ecase ,nuc
;;        ,@pairs)))

;; (defmacro comp (nuc &body body)
;;   `(ecase ,nuc
;;      ,@body))

(defun list-to-pairs (list)
  (loop for (a b) on list
        by #'cddr
        collect (list a b)))

(defmacro comp (nuc &rest pairs)
  `(ecase ,nuc
     ,@(list-to-pairs (mapcar #'symbol-to-char pairs))))

(defun symbol-to-char (symbol) (char (symbol-name symbol) 0))

(defun nuc-comp (nuc)
  (comp nuc
        G C
        C G
        T A
        A U))

(defun to-rna (str)
  "Transcribe a string representing DNA nucleotides to RNA."
  (map 'string #'nuc-comp (string str))) ; Extra (string) is for char inputs


