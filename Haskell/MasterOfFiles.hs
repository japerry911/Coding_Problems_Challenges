{-
---Master of Files---
Are you a file extension master? Let's find out by checking if Bill's files 
are images or audio files. Please use regex if available natively for your language.

You will create 2 string methods:

isAudio/is_audio, matching 1 or + uppercase/lowercase letter(s) (combination 
possible), with the extension .mp3, .flac, .alac, or .aac.

isImage/is_image, matching 1 or + uppercase/lowercase letter(s) (combination 
possible), with the extension .jpg, .jpeg, .png, .bmp, or .gif.

Note that this is not a generic image/audio files checker. It's meant to be a 
test for Bill's files only. Bill doesn't like punctuation. He doesn't like numbers, 
neither. Thus, his filenames are letter-only

Rules

It should return true or false, simply.
File extensions should consist of lowercase letters and numbers only.
File names should consist of letters only (uppercase, lowercase, or both)
Good luck!
-}

import           Text.Regex.Posix.String
import           Text.Regex.Posix

main = print $ isAudio "l.mp3.gif.aac"

isAudio :: FilePath -> Bool
isAudio = matchTest makeAudioRegex

makeAudioRegex :: Regex
makeAudioRegex = makeRegex "^[A-Za-z]+[.](mp3|flac|alac|aac)$"

isImage :: FilePath -> Bool
isImage = matchTest makeImageRegex

makeImageRegex :: Regex
makeImageRegex = makeRegex "^[A-Za-z]+[.](jpg|jpeg|png|bmp|gif)$"
