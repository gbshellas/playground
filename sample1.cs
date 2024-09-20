 public override PlugInResult Execute(CommonPosData data, Dictionary<string, object> Objects)
        {
            try
            {
                _logger.FunctionStart(this);

                ModCntr TheModCntr = null;
                TA taobj = null;
                TaMediaRec MyTaMediaRec = null;
                TaMediaMemberDetailRec MyTaMediaMemberDetailRec = null;

                if (Objects.ContainsKey(ControllerConstants.ModCntr))
                {
                    TheModCntr = (ModCntr)Objects[ControllerConstants.ModCntr];
                }
                if (Objects.ContainsKey(TransactionConstants.TA))
                {
                    taobj = (TA)Objects[TransactionConstants.TA];
                }
                if (Objects.ContainsKey(TransactionConstants.CurrentRecord))
                {
                    MyTaMediaRec = (TaMediaRec)Objects[TransactionConstants.CurrentRecord];
                }
                if (Objects.ContainsKey(TransactionConstants.TaMediaMemberDetailRec))
                {
                    MyTaMediaMemberDetailRec = (TaMediaMemberDetailRec)Objects[TransactionConstants.TaMediaMemberDetailRec];
                }

                clsMedia MyMediaClass = null;
                Dictionary<string, string> MyDict = new Dictionary<string, string>();          

                if (taobj == null)
                {
                    _logger.Error(this, "taobj not set");
                    return PlugInResult.Abort;
                }

                if (TheModCntr == null)
                {
                    _logger.Error(this, "TheModCntr not set");
                    return PlugInResult.Abort;
                }
                if (MyTaMediaRec == null)
                {
                    _logger.Error(this, "TheMediaRec not set");
                    return PlugInResult.Abort;
                }
                MyDict = MyTaMediaRec.ToDictionary();
                if (data.ContainsKey(PaymentConstants.MEDIA_OBJECT))
                {
                    data.RemoveValue(PaymentConstants.MEDIA_OBJECT);
                }
                data.SetValue(PaymentConstants.MEDIA_OBJECT, MyDict);

                if (data.ContainsKey(PaymentConstants.MEDIA_MEMBER_DETAIL_OBJECT))
                {
                    data.RemoveValue(PaymentConstants.MEDIA_MEMBER_DETAIL_OBJECT);
                }

                if (MyTaMediaMemberDetailRec == null)
                {
                    _logger.Debug(this, "MyTaMediaMemberDetailRec not set");
                }
                else
                {
                    MyDict = new Dictionary<string, string>();
                    MyDict = MyTaMediaMemberDetailRec.ToDictionary();
                    data.SetValue(PaymentConstants.MEDIA_MEMBER_DETAIL_OBJECT, MyDict);
                }

                //TODO all 
                MyMediaClass = UtilStandPosModuls.createPosModelObject<clsMedia>(TheModCntr, "clsMedia", MyTaMediaRec.PAYMENTinMedia.lPayType, false);

                if (MyMediaClass == null)
                {
                    //an entry is missing in PosModel for szMediaClassName with Extension of the payment-type
                    //no special handling configured in PosModel for this payment type
                    //everything is ok
                    return PlugInResult.Success;
                }
                else
                {
                    if (MyMediaClass.DoSpecialHandling(ref taobj, ref TheModCntr, ref MyTaMediaRec, ref MyTaMediaMemberDetailRec) == false)
                    {
                        if (data.ErrorNumber == 0)
                        {
                            data.ErrorNumber = PosErr.ERR_INTERNAL_ERR;
                        }
                        return PlugInResult.Error;
                    }
                }

                Dictionary<string, string> MyMap;
                MyMap = MyTaMediaRec.ToDictionary();
                data.SetValue(PaymentConstants.MEDIA_OBJECT, MyMap);

                if (Objects.ContainsKey(TransactionConstants.CurrentRecord))
                {
                    Objects.Remove(TransactionConstants.CurrentRecord);
                }
                Objects.Add(TransactionConstants.CurrentRecord, MyTaMediaRec);

                if (Objects.ContainsKey(TransactionConstants.TaMediaMemberDetailRec))
                {
                    Objects.Remove(TransactionConstants.TaMediaMemberDetailRec);
                }
                if (MyTaMediaMemberDetailRec != null)
                {
                    MyMap = MyTaMediaMemberDetailRec.ToDictionary();
                    data.SetValue(PaymentConstants.MEDIA_MEMBER_DETAIL_OBJECT, MyMap);
                    Objects.Add(TransactionConstants.TaMediaMemberDetailRec, MyTaMediaMemberDetailRec);
                }
            }
            catch (Exception ex)
            {
                _logger.Error(this, ex);
                return PlugInResult.Abort;
            }
            finally
            {
                _logger.FunctionExit(this);
            }

            return PlugInResult.Success;
        }
