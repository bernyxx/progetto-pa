{-# LANGUAGE OverloadedStrings #-}

{-# HLINT ignore "Use camelCase" #-}

import Control.Applicative
import Data.List
import Data.List.Split
import Data.Maybe
import Text.HTML.Scalpel

-- Data una lista di ordinabili, ritorna una lista di tuple di arità 2 contenenti al primo posto il numero di occorrenze della stringa che sta al secondo posto
occu :: Ord a => [a] -> [(Int, a)]
occu [] = []
occu list = map (\l -> (length l, head l)) (group (sort list))

-- Funzione main, legge l'URL in input con getLine(), chiama formatText() che a sua volta chiama scrape_titles() che effettua lo scraping
main :: IO ()
main = do
  print "Inserisci l'indirizzo web: "
  url <- getLine
  text <- formatText url
  print text

-- chiama scrape_titles(), ottiene il testo, offettua gli split sulle frasi per ottenere una lista di singole parole invece che una lista di stringhe e per finire
-- chiama occ su questa lista per contare le occorrenze
formatText :: [Char] -> IO [(Int, [Char])]
formatText url = do
  -- ottieni il testo contenuto nei tag <p> della pagina
  wiki <- scrape_titles url
  
  -- da Maybe[String] a [String]
  let text = fromJust wiki

  -- a partire da una lista di stringhe fondo tutto in un unico test
  -- [String] -> [Char]
  let con = concat text

  -- spezzo la stringa separando le parole, in questo modo ottengo una lista di singole parole
  -- [Char] -> [[Char]]
  let words = splitOn " " con

  -- conta le occorrenze delle parole
  let occ = reverse (sort (occu words))
  return occ

-- funzione che fa lo scraping del testo contenuto nei tag <p> della pagina web scelta
-- restituisce una lista di stringhe (il testo contenuto in ogni tag)
scrape_titles :: [Char] -> IO (Maybe [String])
scrape_titles url = scrapeURL url titles
  where
    titles :: Scraper String [String]
    titles = chroots anySelector titletext

    titletext :: Scraper String String
    titletext = text "p"