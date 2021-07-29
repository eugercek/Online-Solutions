(in-package #:cl-user)
(defpackage #:rna-transcription
  (:use #:cl)
  (:export #:to-rna))
(in-package #:rna-transcription)

(defun to-rna (str)
  "Transcribe a string representing DNA nucleotides to RNA."
  (defun comp (nuc)
    (cond ((char= nuc #\G) #\C)
          ((char= nuc #\C) #\G)
          ((char= nuc #\T) #\A)
          ((char= nuc #\A) #\U)
          (t (error "error"))))
  (map 'string #'nuc-comp (string str))) ; Extra (string) is for char inputs
