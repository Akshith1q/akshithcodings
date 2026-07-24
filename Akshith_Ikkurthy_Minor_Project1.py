import numpy as np
from datetime import datetime
pm=[]
smc=moc=dmc=0
with open('WhatsApp Chat with Maple Tree.txt','r',encoding='utf-8') as f:
    lns=f.readlines()
for l in lns:
    l=l.strip()
    if not l or " - " not in l:
        continue
    ts,r=l.split(" - ",1)
    if ": " not in r:
        smc+=1
        continue
    s,mt=r.split(": ",1)
    if mt=="<Media omitted>":
        moc+=1
    elif mt=="This message was deleted":
        dmc+=1
    pm.append({'ts':ts,'s':s,'t':mt})
tm=len(pm)
def pt(t_s):
    c=t_s.replace('\u202f',' ').upper()
    try:
        return datetime.strptime(c,'%d/%m/%y, %H:%M')
    except ValueError: return datetime.strptime(c,'%d/%m/%y, %I:%M %p')
fdt=pt(pm[0]['ts'])
ldt=pt(pm[-1]['ts'])
td=(ldt-fdt).days+1
mc={}
mbs={}
for m in pm:
    s=m['s']
    mc[s]=mc.get(s,0)+1
    if s not in mbs:
        mbs[s]=[]
    mbs[s].append(m)
tp=len(mc)
sc=sorted(mc.items(),key=lambda x:x[1],reverse=True)
us=[s for s,c in sc]
br={}
if pm:
    cs=pm[0]['s']
    cb=0
    for m in pm:
        s=m['s']
        if s not in br:
            br[s]=[]
        if s==cs:
            cb+=1
        else:
            br[cs].append(cb)
            cs=s
            cb=1
    br[cs].append(cb)
ab={s:sum(b)/len(b) if b else 0 for s,b in br.items()}
stts={}
ck=['okay','safe','eat','sleep','take care','are you','please','reminder','drink water',"don't forget"]
fk=['lol','lmao','haha','rofl','lmfao']
chk=['chill','lite','cool','np','no problem','lyt']
for s,ms in mbs.items():
    tm_=len(ms)
    if tm_==0:
        stts[s]={'sr':1,'ab':0,'nr':0,'dr':0,'aw':0,'qr':0,'cw':0,'fp':0,'chp':0}
        continue
    nm=wc=acm=cw=fw=chw=qm=0
    ad=set()
    for m in ms:
        t=m['t']
        if t in ["<Media omitted>","This message was deleted"]: continue
        dt=pt(m['ts'])
        if dt.hour>=23 or dt.hour<5:
            nm+=1
        ad.add(dt.date())
        wds=t.split()
        wc+=len(wds)
        if len(t)>=3 and (t.isupper() or t.count('!')>=2):
            acm+=1
        if t.strip().endswith('?'):
            qm+=1
        tl=t.lower()
        for k in ck:
            if k in tl: cw+=1
        for k in fk:
            if k in tl: fw+=1
        for k in chk:
            if k in tl: chw+=1
    stts[s]={'sr':(td-len(ad))/td if td>0 else 0,'ab':ab.get(s,0),'nr':nm/tm_,'dr':acm/tm_,'aw':wc/tm_,'qr':qm/tm_,'cw':cw,'fp':fw/tm_,'chp':chw/tm_}
mx_cw=max([v['cw'] for v in stts.values()]+[0])
mx_fp=max([v['fp'] for v in stts.values()]+[0])
mx_chp=max([v['chp'] for v in stts.values()]+[0])
pa={}
for s,st in stts.items():
    if st['sr']>0.60:
        pa[s]="THE GHOST"
    elif st['ab']>3:
        pa[s]="THE SPAMMER"
    elif st['nr']>0.60:
        pa[s]="THE NIGHT OWL"
    elif st['aw']>30:
        pa[s]="THE STORYTELLER"
    elif st['dr']>0.30:
        pa[s]="THE DRAMA QUEEN"
    elif st['qr']>0.25:
        pa[s]="THE QUESTION MASTER"
    elif st['cw']==mx_cw and mx_cw>0:
        pa[s]="THE GROUP MOM"
    elif st['fp']==mx_fp and mx_fp>0:
        pa[s]="THE COMEDIAN"
    elif st['chp']==mx_chp and mx_chp>0:
        pa[s]="THE CHILL GUY"
    else:
        pa[s]="THE CHATTERBOX"
print(f"{'='*80}\nGROUP OVERVIEW & ARCHETYPES\n{'='*80}\n{'Group':<15}: Maple Tree\n{'Period':<15}: {fdt.strftime('%d %b %Y')} to {ldt.strftime('%d %b %Y')} ({td} days)\n{'Total messages':<15}: {tm:,}\n{'Participants':<15}: {tp}\n{'-'*80}\nMESSAGES PER PERSON")
for s,c in sc:
    print(f"{s:<20} : {c:>5} ({(c/tm)*100:>5.1f}%)   ->  {pa[s]}")
dc,hc={},{}
for m in pm:
    dt=pt(m['ts'])
    d=dt.strftime('%d %B %Y')
    h=dt.hour
    dc[d]=dc.get(d,0)+1
    hc[h]=hc.get(h,0)+1
bd=max(dc.items(),key=lambda x:x[1])
bh=max(hc.items(),key=lambda x:x[1])
print(f"{'Busiest day':<15}: {bd[0]} ({bd[1]} messages)\n{'Busiest hour':<15}: {bh[0]:02d}:00 - {(bh[0]+1)%24:02d}:00 (avg {bh[1]//td} messages per day)")
sw={'i','is','the','a','and','or','to','of','in','on','for','it','this','that','you','my','me','with','hai','ki','se','ko','hi','bhai','bro','mera','tu','mai'}
wd={}
for m in pm:
    t=m['t']
    if t in ["<Media omitted>","This message was deleted"]:
        continue
    wl=t.split()
    for w in wl:
        cw_w=w.lower().strip('.,!?()[]{}"\'*~-_')
        if cw_w and cw_w not in sw:
            wd[cw_w]=wd.get(cw_w,0)+1
t10=sorted(wd.items(),key=lambda x:x[1],reverse=True)[:10]
print(f"\n{'='*80}\nTHIS GROUP'S FAVOURITE WORDS\n{'='*80}")
mxc=t10[0][1] if t10 else 1
for w,c in t10:
    print(f"{w:<15} {c:>5}  {'█'*int((c/mxc)*20)}")
rt={s:[] for s in us}
ps=ptm=None
for m in pm:
    s=m['s']
    t=pt(m['ts'])
    if ps and ps!=s:
        g=(t-ptm).total_seconds()
        if g>=0:
            rt[s].append(g)
    ps,ptm=s,t
art={s:sum(g)/len(g) if g else 0 for s,g in rt.items()}
srt=sorted([i for i in art.items() if i[1]>0],key=lambda x:x[1])
ss={s:0 for s in us}
fd,ld=fdt.date(),ldt.date()
for s in us:
    ud=sorted(list({pt(m['ts']).date() for m in mbs[s]}))
    if not ud: ss[s]=td
    else:
        mx=(ud[0]-fd).days
        for i in range(1,len(ud)): mx=max(mx,(ud[i]-ud[i-1]).days-1)
        ss[s]=max(mx,(ld-ud[-1]).days)
sss=sorted(ss.items(),key=lambda x:x[1],reverse=True)
print(f"\n{'='*80}\nRESPONSE PATTERNS")
if srt:
    f,s_=srt[0],srt[-1]
    print(f"Fastest replier: {f[0]} (avg {f[1]/60:.1f} mins)\nSlowest replier: {s_[0]} (avg {s_[1]/3600:.1f} hours)")
print("\nLONGEST SILENT STREAKS")
for s,d in sss:
    print(f"{s:<20} : {d} days")
s2i={s:i for i,s in enumerate(us)}
hm=np.zeros((len(us),24),dtype=int)
for m in pm:
    hm[s2i[m['s']],pt(m['ts']).hour]+=1
print(f"\n{'='*80}\nACTIVITY HEATMAP (messages by hour)\n{'':<20} 12a 3a 6a 9a 12p 3p 6p 9p")
for i,s in enumerate(us):
    rd=hm[i]
    pmx=np.max(rd) or 1
    vr="".join([' ' if (c/pmx)*100==0 else '.' if (c/pmx)*100<=25 else '░' if (c/pmx)*100<=50 else '▒' if (c/pmx)*100<=75 else '▓' for c in rd])
    print(f"{s:<20} {vr}")
print("="*80)