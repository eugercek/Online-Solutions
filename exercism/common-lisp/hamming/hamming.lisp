(defpackage #:hamming
  (:use #:cl)
  (:export #:distance))

(in-package #:hamming)

(defun distance (dna1 dna2)
  "Number of positional differences in two equal length dna strands."
  (unless (/= (length dna1) (length dna2))
      (loop for c1 across dna1
            for c2 across dna2
            count (char/= c1 c2))))
