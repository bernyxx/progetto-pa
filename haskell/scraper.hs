{-# LANGUAGE OverloadedStrings #-}

{-# HLINT ignore "Use camelCase" #-}

import Control.Applicative
import Data.List
import Data.List.Split
import Data.Maybe
import Text.HTML.Scalpel

occu :: Ord a => [a] -> [(Int, a)]
occu [] = []
occu list = map (\l -> (length l, head l)) (group (sort list))

main :: IO ()
main = do
  url <- getLine
  text <- formatText url
  print text

formatText :: [Char] -> IO [(Int, [Char])]
formatText url = do
  wiki <- scrape_titles url
  let text = fromJust wiki
  let con = concat text
  let words = splitOn " " con
  let occ = reverse (sort (occu words))
  return occ

scrape_titles :: [Char] -> IO (Maybe [String])
scrape_titles url = scrapeURL url titles
  where
    titles :: Scraper String [String]
    titles = chroots anySelector titletext

    titletext :: Scraper String String
    titletext = text "p"