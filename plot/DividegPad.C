void DividegPad(Int_t nx, Int_t ny,
                Float_t l, Float_t r, Float_t t, Float_t b)
{
   Int_t ix, iy, n=0;
   Double_t x1, x2, y1, y2;
   Double_t dx = ((1-r)*(1-l))/((1-r)*(1-l)*(nx-2)-r+2-l);
   Double_t dl = dx/(1-l);
   Double_t dy = ((1-t)*(1-b))/((1-t)*(1-b)*(ny-2)-t+2-b);
   Double_t db = dy/(1-b);
   char* name  = new char [strlen(gPad->GetName())+6];
                                                                                
   y1 = 0;
   y2 = db;
   for (iy=0;iy<ny;++iy) {
      x1 = 0;
      x2 = dl;
      for (ix=0;ix<nx;ix++) {
         if (x1>x2) continue;
         n++;
         sprintf(name,"%s_%d",gPad->GetName(),n);
         pad = new TPad(name,name,x1,y1,x2,y2,0);
         if (ix==0)    pad->SetLeftMargin(l);
         if (ix==nx-1) pad->SetRightMargin(r);
         if (iy==ny-1) pad->SetTopMargin(t);
         if (iy==0)    pad->SetBottomMargin(b);
         x1 = x2;
         if (ix==nx-2) {
            x2 = 1;
         } else {
            x2 = x1+dx;
         }
         pad->SetNumber(n);
         pad->Draw();
      }
      y1 = y2;
      if (iy==ny-2) {
         y2 = 1;
      } else {
         y2 = y1+dy;
      }
   }

}
