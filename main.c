#include <stdio.h>
#include <stdlib.h>
#define ucak_kapasite 24

struct plane
{
    int oncelik_id ,ucak_id ,tale_edilen_inis_saat;

    int gecikme, inis_saati ,kalkis_saati;
    struct plane *next;
};
typedef struct plane ucak;

int toplam_ucak_sayisi=28;
int ucak_sayisi=0;

ucak *inis_pisti_kullanim_sirasi=NULL;
ucak *kalkis_pisti_kullanim_sirasi=NULL;

int dosya_konum=0;


ucak *inis_sirasi_duzenle(ucak *temp)
{
    ucak *gezer=NULL;
    ucak *kuyruk=NULL;
    ucak *kuyruk_k=NULL;

    if(inis_pisti_kullanim_sirasi==NULL)
    {
        inis_pisti_kullanim_sirasi=temp;

        inis_pisti_kullanim_sirasi->kalkis_saati=1 + inis_pisti_kullanim_sirasi->inis_saati;

        return inis_pisti_kullanim_sirasi;
    }

    if(temp->inis_saati==inis_pisti_kullanim_sirasi->inis_saati && temp->oncelik_id < inis_pisti_kullanim_sirasi->oncelik_id)
    {
          temp->next=inis_pisti_kullanim_sirasi;
          temp->kalkis_saati=1 + temp->inis_saati;

          gezer=inis_pisti_kullanim_sirasi;
          kuyruk=temp;
          kuyruk_k=temp;

           gezer->gecikme++;
           gezer->inis_saati=gezer->tale_edilen_inis_saat + gezer->gecikme;
           gezer->kalkis_saati=gezer->inis_saati + 1;

           while(gezer->next!=NULL && gezer->next->inis_saati==gezer->inis_saati)
             {
              if(gezer->oncelik_id > gezer->next->oncelik_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                      //printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                           // printf("Artik gondermem gerek !!!!\n"); // an itibariyle kuyruk onceligi daha buyuk oldugundan o silinecektir
                           printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                          //  printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return temp;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }

              }

              else if(gezer->oncelik_id==gezer->next->oncelik_id && gezer->ucak_id > gezer->next->ucak_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                     // printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                         //   printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk ucak_id daha buyuk oldugundan o silinecektir
                            printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                          //  printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return temp;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }


              }

              else
              {
                 // kuyruk=kuyruk->next;
                    gezer=gezer->next;
                  /*  if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;*/

                     gezer->gecikme++;

                if(gezer->gecikme > 3)
                {
                    gezer->gecikme--;
                    gezer=kuyruk->next;
                    gezer->gecikme++;


                 if(gezer->gecikme > 3)
                 {
                    gezer->gecikme--;
                    gezer=gezer->next;
                    kuyruk=kuyruk->next;
                    if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                  //  printf("Artik silmen gerek...\n"); //ertelemem gerekiyor ama edemiyorum
                     printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",gezer->oncelik_id,gezer->ucak_id,gezer->tale_edilen_inis_saat);
                    ucak *sil=gezer;
                 //   printf("%d id li ucak silindi.\n",sil->ucak_id);

                    kuyruk->next=gezer->next;
                    free(sil);
                    ucak_sayisi--;
                    return inis_pisti_kullanim_sirasi;

                 }
                 else
                 {
                     kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;

                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                 }


                }

                else
                {


                   kuyruk=kuyruk->next;
                   if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                   gezer->inis_saati=gezer->tale_edilen_inis_saat + gezer->gecikme;
                    gezer->kalkis_saati=gezer->inis_saati + 1;
                }
              }

             }


           return temp;
    }

    if(temp->inis_saati < inis_pisti_kullanim_sirasi->inis_saati)
    {
        temp->next=inis_pisti_kullanim_sirasi;
        temp->kalkis_saati=temp->inis_saati + 1;

        return temp;
    }


     ucak *iter=inis_pisti_kullanim_sirasi;

    while(iter->next!=NULL && iter->next->inis_saati <= temp->inis_saati)
    {

        if(iter->next->inis_saati == temp->inis_saati && temp->oncelik_id < iter->next->oncelik_id)
        {
          iter->next->inis_saati++;
          if(iter->next->inis_saati > 3)
          {
              iter->next->inis_saati--;
             // printf("Attik erteleyemem !!!\n");
              temp->next=iter->next->next;
              iter->next->next=temp;

              kuyruk=iter->next;
              kuyruk_k=iter->next;
              gezer=temp;

              gezer->gecikme++;
              gezer->inis_saati=gezer->gecikme+gezer->tale_edilen_inis_saat;
              gezer->kalkis_saati=gezer->inis_saati + 1;

              while(gezer->next!=NULL && gezer->next->inis_saati==gezer->inis_saati)
              {
              if(gezer->oncelik_id > gezer->next->oncelik_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                    //  printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                         //   printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk onceligi daha buyuk oldugundan o silinecektir
                             printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                           // printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }

              }

              else if(gezer->oncelik_id==gezer->next->oncelik_id && gezer->ucak_id > gezer->next->ucak_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                   //   printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                          //  printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk ucak_id daha buyuk oldugundan o silinecektir
                              printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                          //  printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }


              }

              else
              {
                 // kuyruk=kuyruk->next;
                    gezer=gezer->next;
                  /*  if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;*/

                     gezer->gecikme++;

                if(gezer->gecikme > 3)
                {
                    gezer->gecikme--;
                    gezer=kuyruk->next;
                    gezer->gecikme++;


                 if(gezer->gecikme > 3)
                 {
                    gezer->gecikme--;
                    gezer=gezer->next;
                    kuyruk=kuyruk->next;
                    if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                  //  printf("Artik silmen gerek...\n"); //ertelemem gerekiyor ama edemiyorum
                     printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",gezer->oncelik_id,gezer->ucak_id,gezer->tale_edilen_inis_saat);
                    ucak *sil=gezer;
                 //   printf("%d id li ucak silindi.\n",sil->ucak_id);

                    kuyruk->next=gezer->next;
                    free(sil);
                    ucak_sayisi--;
                    return inis_pisti_kullanim_sirasi;

                 }
                 else
                 {
                     kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;

                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                 }


                }

                else
                {


                   kuyruk=kuyruk->next;
                   if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                   gezer->inis_saati=gezer->tale_edilen_inis_saat + gezer->gecikme;
                    gezer->kalkis_saati=gezer->inis_saati + 1;
                }
              }

              }

          }

          else
          {
              temp->next=iter->next;
              iter->next=temp;

              kuyruk=temp;
              kuyruk_k=temp;
              gezer=temp->next;

              gezer->inis_saati=gezer->gecikme+gezer->tale_edilen_inis_saat;
              gezer->kalkis_saati=gezer->inis_saati + 1;

              while(gezer->next!=NULL && gezer->next->inis_saati==gezer->inis_saati)
              {
              if(gezer->oncelik_id > gezer->next->oncelik_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                   //   printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                        //    printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk onceligi daha buyuk oldugundan o silinecektir
                             printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                          //  printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }

              }

              else if(gezer->oncelik_id==gezer->next->oncelik_id && gezer->ucak_id > gezer->next->ucak_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                   //   printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                        //    printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk ucak_id daha buyuk oldugundan o silinecektir
                              printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                         //   printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }


              }

              else
              {
                 // kuyruk=kuyruk->next;
                    gezer=gezer->next;
                  /*  if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;*/

                     gezer->gecikme++;

                if(gezer->gecikme > 3)
                {
                    gezer->gecikme--;
                    gezer=kuyruk->next;
                    gezer->gecikme++;


                 if(gezer->gecikme > 3)
                 {
                    gezer->gecikme--;
                    gezer=gezer->next;
                    kuyruk=kuyruk->next;
                    if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                  //  printf("Artik silmen gerek...\n"); //ertelemem gerekiyor ama edemiyorum
                     printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",gezer->oncelik_id,gezer->ucak_id,gezer->tale_edilen_inis_saat);
                    ucak *sil=gezer;
                 //   printf("%d id li ucak silindi.\n",sil->ucak_id);

                    kuyruk->next=gezer->next;
                    free(sil);
                    ucak_sayisi--;
                    return inis_pisti_kullanim_sirasi;

                 }
                 else
                 {
                     kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;

                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                 }


                }

                else
                {


                   kuyruk=kuyruk->next;
                   if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                   gezer->inis_saati=gezer->tale_edilen_inis_saat + gezer->gecikme;
                    gezer->kalkis_saati=gezer->inis_saati + 1;
                }
              }

              }

          }


            return inis_pisti_kullanim_sirasi;
        }
        iter=iter->next;

    }

           temp->next=iter->next;
            iter->next=temp;

            kuyruk=iter;
            kuyruk_k=iter;
            gezer=temp;

            if(gezer->inis_saati==kuyruk->inis_saati)
            {
                gezer->gecikme++;
                gezer->inis_saati=gezer->gecikme+gezer->tale_edilen_inis_saat;
                gezer->kalkis_saati=gezer->inis_saati + 1;

              while(gezer->next!=NULL && gezer->next->inis_saati==gezer->inis_saati)
              {
              if(gezer->oncelik_id > gezer->next->oncelik_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                     // printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                        //    printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk onceligi daha buyuk oldugundan o silinecektir
                            printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                        //    printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }

              }

              else if(gezer->oncelik_id==gezer->next->oncelik_id && gezer->ucak_id > gezer->next->ucak_id)
              {
                  gezer->gecikme++;
                  if(gezer->gecikme > 3)
                  {
                    //  printf("Daha fazla geciktiremem!!!\n");

                      gezer->gecikme--;

                      gezer=gezer->next;
                      kuyruk=kuyruk->next;
                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->gecikme++;

                        if(gezer->gecikme > 3)
                        {
                            gezer->gecikme--;

                          //  printf("Artik silmem gerek !!!!\n"); // an itibariyle kuyruk ucak_id daha buyuk oldugundan o silinecektir
                             printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",kuyruk->oncelik_id,kuyruk->ucak_id,kuyruk->tale_edilen_inis_saat);
                            ucak *sil=kuyruk;
                          //  printf("%d id li ucak silindi!!!\n",sil->ucak_id);
                            kuyruk_k->next=gezer;
                            free(sil);
                            ucak_sayisi--;
                            return inis_pisti_kullanim_sirasi;

                        }
                        else
                        {
                            gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                            gezer->kalkis_saati=gezer->inis_saati + 1;
                        }

                  }
                  else
                  {
                       kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;
                        if(kuyruk_k->next!=kuyruk)
                            kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                  }


              }


              else
              {
                 // kuyruk=kuyruk->next;
                    gezer=gezer->next;
                  /*  if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;*/

                     gezer->gecikme++;

                if(gezer->gecikme > 3)
                {
                    gezer->gecikme--;
                    gezer=kuyruk->next;
                    gezer->gecikme++;


                 if(gezer->gecikme > 3)
                 {
                    gezer->gecikme--;
                    gezer=gezer->next;
                    kuyruk=kuyruk->next;
                    if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                  //  printf("Artik silmen gerek...\n"); //ertelemem gerekiyor ama edemiyorum
                     printf("%d %d %d bilgili ucak daha fazla geciktirme islemi uygulanamadigindan Sabiha Gokcen havalimanina yonlendiriliyor\n",gezer->oncelik_id,gezer->ucak_id,gezer->tale_edilen_inis_saat);
                    ucak *sil=gezer;
                 //   printf("%d id li ucak silindi.\n",sil->ucak_id);

                    kuyruk->next=gezer->next;
                    free(sil);
                    ucak_sayisi--;
                    return inis_pisti_kullanim_sirasi;

                 }
                 else
                 {
                     kuyruk->next=gezer->next;
                       gezer->next=gezer->next->next;
                       kuyruk->next->next=gezer;

                        kuyruk=kuyruk->next;

                      if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;

                        gezer->inis_saati=gezer->gecikme + gezer->tale_edilen_inis_saat;
                        gezer->kalkis_saati=gezer->inis_saati + 1;
                 }


                }

                else
                {


                   kuyruk=kuyruk->next;
                   if(kuyruk_k->next!=kuyruk)
                        kuyruk_k=kuyruk_k->next;
                   gezer->inis_saati=gezer->tale_edilen_inis_saat + gezer->gecikme;
                    gezer->kalkis_saati=gezer->inis_saati + 1;
                }
              }

              }

                return inis_pisti_kullanim_sirasi;

            }

            temp->kalkis_saati=temp->inis_saati + 1;

             return inis_pisti_kullanim_sirasi;

}




void display_queue()
{
    ucak *iter=inis_pisti_kullanim_sirasi;
    while(iter!=NULL)
    {

        printf("\n%d:oncelik_id  %d:ucak_id  %d:talep_inis  ||  %d:gecikme  ",iter->oncelik_id,iter->ucak_id,iter->tale_edilen_inis_saat,iter->gecikme);
        if(iter->inis_saati > 24)
        {
            printf("%d:inis  ",iter->inis_saati-24);
        }
        else
        {
            printf("%d:inis  ",iter->inis_saati);
        }
        if(iter->kalkis_saati > 24)
        {
            printf("%d:kalkis\n",iter->kalkis_saati-24);
        }
        else
        {
             printf("%d:kalkis\n",iter->kalkis_saati);
        }

        iter=iter->next;
    }
}



void inis_izni()
{
    ucak *temp=(ucak *)malloc(sizeof(ucak));

    FILE *dosyaptr=fopen("input.txt","r");
    if(dosyaptr==NULL)
    {
        printf("Dosya acilamadi.\n");
        return NULL;
    }
     fseek(dosyaptr,dosya_konum,SEEK_SET);

           fscanf(dosyaptr,"%d%d%d",&temp->oncelik_id,&temp->ucak_id,&temp->tale_edilen_inis_saat);
            temp->gecikme=0;
            temp->inis_saati=temp->tale_edilen_inis_saat;
            temp->kalkis_saati=0;
            temp->next=NULL;

    dosya_konum=ftell(dosyaptr);

    fclose(dosyaptr);

    ucak *iter=NULL;

    if(ucak_sayisi!=ucak_kapasite || temp->oncelik_id==2 ||temp->oncelik_id==1)
    {
           printf("\n---------------------------------------------\n");
           printf("%d %d %d bilgili ucak icin inis izni verilmistir.\n",temp->oncelik_id,temp->ucak_id,temp->tale_edilen_inis_saat);
            printf("---------------------------------------------\n");
           inis_pisti_kullanim_sirasi=inis_sirasi_duzenle(temp);
           kalkis_pisti_kullanim_sirasi=inis_pisti_kullanim_sirasi;

           dosyaptr=fopen("output.txt","w");
            if(dosyaptr==NULL)
            {
                 printf("Dosya acilamadi.\n");
                  return NULL;
            }


           while(kalkis_pisti_kullanim_sirasi!=NULL)
           {
               fprintf(dosyaptr,"%d %d %d ",kalkis_pisti_kullanim_sirasi->oncelik_id,kalkis_pisti_kullanim_sirasi->ucak_id,kalkis_pisti_kullanim_sirasi->tale_edilen_inis_saat);
               if(kalkis_pisti_kullanim_sirasi->inis_saati > 24)
               {
                   fprintf(dosyaptr,"%d ",kalkis_pisti_kullanim_sirasi->inis_saati - 24);
               }
               else
               {
                   fprintf(dosyaptr,"%d ",kalkis_pisti_kullanim_sirasi->inis_saati);
               }
               fprintf(dosyaptr,"%d ",kalkis_pisti_kullanim_sirasi->gecikme);
               if(kalkis_pisti_kullanim_sirasi->kalkis_saati > 24)
               {
                   fprintf(dosyaptr,"%d\n",kalkis_pisti_kullanim_sirasi->kalkis_saati - 24);
               }
               else
               {
                   fprintf(dosyaptr,"%d\n",kalkis_pisti_kullanim_sirasi->kalkis_saati);
               }
               kalkis_pisti_kullanim_sirasi=kalkis_pisti_kullanim_sirasi->next;
           }
           fclose(dosyaptr);

           ucak_sayisi++;
    }


    else
    {
        printf("\n---------------------------------------------\n");
        printf("%d id %d oncelikli %d talep edilen inis saatli  ucak icin kapasite doldugundan izin verilmemistir sizi Sabiha Gokcen hava limanina yonlendiriyoruz.\n",temp->ucak_id,temp->oncelik_id,temp->tale_edilen_inis_saat);
        printf("---------------------------------------------\n");
    }


}


int main()
{
    for(int i=0; i<13; i++)
    {
        inis_izni();
         display_queue();
    }

    return 0;
}
