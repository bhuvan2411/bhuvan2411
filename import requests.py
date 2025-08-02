# Script to fetch live prices for Indian stocks using ISIN-ticker mapping
# Usage: Run this script in a Python environment with yfinance and tabulate installed.
# The ISIN-ticker mapping below covers major NSE stocks. Add or update ISINs as needed.
isin_ticker_map = {
    "INE674K01013": "NSE:ABCAPITAL",
    "INE238A01034": "NSE:AXISBANK",
    "INE180C01042": "NSE:CGCL",
    "INE757A01017": "NSE:COSMOFIRST",
    "INE089A01031": "NSE:DRL",
    "INE235A01022": "NSE:FINCABLES",
    "INE183A01024": "NSE:FINPIPE",
    "INE040A01034": "NSE:HDFCBANK",
    "INE158A01026": "NSE:HEROMOTOCO",
    "INE726G01019": "NSE:ICICIPRULI",
    "INE092T01019": "NSE:IDFCFIRSTB",
    "INE095A01012": "NSE:INDUSINDBK",
    "INE009A01021": "NSE:INFY",
    "INE379A01028": "NSE:ITCHOTELS",
    "INE154A01025": "NSE:ITC",
    "INE668F01031": "NSE:JYOTHYLAB",
    "INE998I01010": "NSE:MHRIL",
    "INE522D01027": "NSE:MANAPPURAM",
    "INE414G01012": "NSE:MUTHOOTFIN",
    "INE987B01026": "NSE:NATCOPHARM",
    "INF204KB17I5": "NSE:GOLDBEES",
    "INF204KB15V2": "NSE:NIFTYIT",
    "INE347G01014": "NSE:PETRONET",
    "INE0GGX23010": "NSE:PGINVIT",
    "INE572J01011": "NSE:SPANDANA",
    "INE00IN01015": "NSE:STOVEKRAFT",
    "INE668A01016": "NSE:TMB",
    "INE092A01019": "NSE:TATACHEM",
    "INE155A01022": "NSE:TATAMOTORS",
    "INE081A01020": "NSE:TATASTEEL",
    "INE467B01029": "NSE:TCS",
    "INE669C01036": "NSE:TECHM",
    "INE085J01014": "NSE:THANGAMAYL",
    "INE171A01029": "NSE:FEDERALBNK",
    "INE614B01018": "NSE:KTKBANK",
    "INE683A01023": "NSE:SOUTHBANK",
    "INE195A01028": "NSE:SUPREMEIND",
    "INE690A01028": "NSE:TTKPRESTIG",
    "INE075A01022": "NSE:WIPRO",
    "INE010B01027": "NSE:ZYDUSLIFE",
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
    "INE885A01032": "NSE:ARE&M",
    "INE987B01026": "NSE:NATCOPHARM",
    "INE669C01036": "NSE:TECHM",
    "INE085J01014": "NSE:THANGAMAYL",
    "INE010B01027": "NSE:ZYDUSLIFE"
}

isin_list = list(isin_ticker_map.keys())


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