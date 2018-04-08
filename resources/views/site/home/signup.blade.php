@extends('site.home.templates.templateSignup')

@section('content')



<div class="container" style="padding-top: 80px; padding-bottom: 200px; width: 70%">
<form action="{{ route('signup.store') }}" method="POST">
<input type="hidden" name="_token" value="{{ csrf_token() }}">

  <div class="form-row">
    <div class="form-group col-md-6">
      <label>Nome</label>
      <input type="text" name="nome" class="form-control" placeholder="Nome" required="true">
    </div>
    <div class="form-group col-md-6">
      <label>Sobrenome</label>
      <input type="text" name="sobrenome" class="form-control" placeholder="Sobrenome" required="true">
    </div>
  </div>
  
 <div class="form-row">
    <div class="form-group col-md-2">
      <label>Idade</label>
      <input type="text" name="idade" class="form-control" placeholder="Idade" required="true">
    </div>
    <div class="form-group col-md-3">
      <label>CPF</label>
      <input type="text"
      id="CPF" name="cpf" class="form-control" placeholder="CPF" required="true" maxlength="8">
    </div>
    <div class="form-group col-md-3">
      <label>CEP</label>
      <input type="text" id="CEP" name="cep" class="form-control" placeholder="CEP" required="true" maxlength="8">
    </div>
 
    </div>


 <div class="form-row">
     <div class="form-group col-md-5">
      <label>Email</label>
      <input type="email" name="email" class="form-control" placeholder="Email" required="true">
    </div>
     <div class="form-group col-md-5">
      <label>Senha</label>
      <input type="password" id="senha_info" name="password" class="form-control" placeholder="Senha" required="true" minlength="5" maxlength="10">

<br>



 </div>
  


  </div>

<div class="container text-center" style="width: 50%">
    
<button type="submit" id="btn" class="btn btn-primary">Sign up</button>


</div>


  
 
</form>
</div>



@endsection