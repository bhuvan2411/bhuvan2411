isin_ticker_map = {
    "INE009A01021": "NSE:INFY",
    "INE081A01020": "NSE:TATASTEEL",
    "INE089A01031": "NSE:DRL",
    "INE092A01019": "NSE:TATACHEM",
    "INE092T01019": "NSE:IDFCFIRSTB",
    "INE154A01025": "NSE:ITC",
    "INE155A01022": "NSE:TATAMOTORS",
    "INE171A01029": "NSE:FEDERALBNK",
    "INE192A01025": "NSE:TATACONSUM",
    "INE302A01020": "NSE:EXIDEIND",
    "INE361B01024": "NSE:DIVISLAB",
    "INE379A01028": "NSE:ITCHOTELS",
    "INE414G01012": "NSE:MUTHOOTFIN",
    "INE572J01011": "NSE:SPANDANA",
    "INE668A01016": "NSE:TMB",
    "INE683A01023": "NSE:SOUTHBANK",
    "INE885A01032": "NSE:AMARAJABAT",
    "INE987B01026": "NSE:NATCOPHARM",
    "INE669C01036": "NSE:TECHM",
    "INE085J01014": "NSE:THANGAMAYL",
    "INE010B01027": "NSE:ZYDUSLIFE"
}

import yfinance as yf
from tabulate import tabulate

results = []
for isin, ticker in isin_ticker_map.items():
    if ticker.startswith("NSE:"):
        yf_ticker = ticker.replace("NSE:", "") + ".NS"
        stock = yf.Ticker(yf_ticker)
        price = stock.info.get('regularMarketPrice')
        results.append([isin, yf_ticker, price if price is not None else "Not available"])

print(tabulate(results, headers=["ISIN", "Ticker", "Yahoo Finance Last Price"], tablefmt="pretty"))