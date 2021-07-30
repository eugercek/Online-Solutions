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

(defmacro comp (nuc &body body)
  (let ((pairs
          (loop for (a b) in body
                collect `(,a ,b))))
    `(case ,nuc
       ,@pairs
       (t 'error))))

(defun nuc-comp (nuc)
  (comp nuc
    (#\G #\C)
    (#\C #\G)
    (#\T #\A)
    (#\A #\U)))

(defun to-rna (str)
  "Transcribe a string representing DNA nucleotides to RNA."
  (map 'string #'nuc-comp (string str))) ; Extra (string) is for char inputs
